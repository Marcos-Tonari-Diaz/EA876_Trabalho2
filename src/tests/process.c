#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

enum color
{ 
    RED, 
    GREEN, 
    BLUE 
};

void* process_box(void* args){
	int i;
	imagem img;
	img = abrir_imagem("../../data/cachorro.jpg");
       	
	imagem imgOut;
	imgAlloc(&imgOut, img.width, img.height);

	int N = 5;
	float boxBlurKernel[N*N] ;
	for (i=0; i<(N*N); i++){
		boxBlurKernel[i]=(float)1/((float)N*N);
	}

	// faz a convolucao dependendo do canal
	void channelSelect(int channel){
		if (channel==RED){
			for (i=0; i<(img.height); i++) {
				simpleLineConv(img.r, img.width, img.height, 0, i, boxBlurKernel, N, &(imgOut.r[i*img.width]));
			}
		else if (channel==GREEN){
			for (i=0; i<(img.height); i++) {
				simpleLineConv(img.g, img.width, img.height, 0, i, boxBlurKernel, N, &(imgOut.g[i*img.width]));
			}
		else if (channel==BLUE){
			for (i=0; i<(img.height); i++) {
				simpleLineConv(img.b, img.width, img.height, 0, i, boxBlurKernel, N, &(imgOut.b[i*img.width]));
			}
		return;
	}

	// processos usados
	pid_t filhos[3];

  	// implementacao em processos: cada processo atua em um canal de cor
	for (i=0;i<3;i++){
		filhos[i]=fork();
		if (filhos[i]==0){
			channelSelect(i);
		}
	}	

	//espera os processos filhos terminarem
	for (i=0;i<4;i++){
		waitpid(filhos[i], NULL, 0);
	}
	
  	salvar_imagem("cachorroProcessBox.jpg", &imgOut);
	imgFree(&imgOut);
}
