#include "linear_box.h"

void* linear_box(void* args){
        //iteracao atual
	int iter = *((int*) args);

	//abre a imagem
	int i;
	imagem img;
	img = abrir_imagem("data/cachorro.jpg");
       	
	// imagem de saida
	imagem imgOut;
	imgAlloc(&imgOut, img.width, img.height);

	// cria o Kernel BoxBlur
	int N = 8;
	float boxBlurKernel[N*N] ;
	for (i=0; i<(N*N); i++){
		boxBlurKernel[i]=(float)1/((float)N*N);
	}
  	
	// realiza a convolucao em todas as linhas dos 3 canais de cor
	for (i=0; i<(img.height); i++) {
		simpleLineConv(img.r, img.width, img.height, 0, i, boxBlurKernel, N, &(imgOut.r[i*img.width]));
		simpleLineConv(img.g, img.width, img.height, 0, i, boxBlurKernel, N, &(imgOut.g[i*img.width]));
		simpleLineConv(img.b, img.width, img.height, 0, i, boxBlurKernel, N, &(imgOut.b[i*img.width]));
	}
	// libera o heap e salva a imagem na ultima iteracao
	liberar_imagem(&img);
	if (iter==99)
    		salvar_imagem("resultados/cachorro_linear.jpg", &imgOut);
	imgFree(&imgOut);
	return NULL;
}
