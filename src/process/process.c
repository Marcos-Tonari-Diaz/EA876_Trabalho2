#include "process.h"

#define N_PROCESSOS 3

// canais de cor
enum color
{ 
    RED, 
    GREEN, 
    BLUE 
};

void* processo_conv(void* args){
	//iteracao atual	
	int iter = *((int*) args);

	int i;
	// entrada
	imagem img = abrir_imagem("data/cachorro.jpg");

	// na versao em processo, inicio a struct manualmente	
	imagem imgOut;
	imgOut.height=img.height;
	imgOut.width=img.width;

	//Por memoria compartilhada
	/* Definir flags de protecao e visibilidade de memoria */
	int protection = PROT_READ | PROT_WRITE;
	int visibility = MAP_SHARED | MAP_ANON;

	// os canais de imgOut sao memoria compartilhada
	imgOut.r = (float*) mmap(NULL, sizeof(float)*img.width*img.height, protection, visibility, 0, 0);
	imgOut.g = (float*) mmap(NULL, sizeof(float)*img.width*img.height, protection, visibility, 0, 0);
	imgOut.b = (float*) mmap(NULL, sizeof(float)*img.width*img.height, protection, visibility, 0, 0);

	// Kernel
	int N = 8;
	float boxBlurKernel[N*N] ;
	for (i=0; i<(N*N); i++){
		boxBlurKernel[i]=(float)1/((float)N*N);
	}

	// processos utilizados
	pid_t filhos[N_PROCESSOS];

  	// implementacao em processos: cada processo atua em um canal de cor
	for (i=0;i<N_PROCESSOS ;i++){
		filhos[i]=fork();
		if (filhos[i]==0){
			if (i==RED){
				for (i=0; i<(img.height); i++) {
					simpleLineConv(img.r, img.width, img.height, 0, i, boxBlurKernel, N, &(imgOut.r[i*img.width]));
				}
			}
			else if (i==GREEN){
				for (i=0; i<(img.height); i++) {
					simpleLineConv(img.g, img.width, img.height, 0, i, boxBlurKernel, N, &(imgOut.g[i*img.width]));
				}
			}
			else if (i==BLUE){
				for (i=0; i<(img.height); i++) {
					simpleLineConv(img.b, img.width, img.height, 0, i, boxBlurKernel, N, &(imgOut.b[i*img.width]));
				}
			}
			exit(0);
		}
	}	
    	liberar_imagem(&img);
	//espera os processos filhos terminarem
	for (i=0;i<N_PROCESSOS;i++){
		waitpid(filhos[i], NULL, 0);
	}
	if (iter==99)
    		salvar_imagem("cachorro_process.jpg", &imgOut);
    return NULL;
}
