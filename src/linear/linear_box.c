#include "linear_box.h"

void* linear_box(void* args){
	int i;
	imagem img;
	img = abrir_imagem("data/cachorro.jpg");
       	
	imagem imgOut;
	imgAlloc(&imgOut, img.width, img.height);

	int N = 8;
	float boxBlurKernel[N*N] ;
	for (i=0; i<(N*N); i++){
		boxBlurKernel[i]=(float)1/((float)N*N);
	}
  	
	for (i=0; i<(img.height); i++) {
		simpleLineConv(img.r, img.width, img.height, 0, i, boxBlurKernel, N, &(imgOut.r[i*img.width]));
		simpleLineConv(img.g, img.width, img.height, 0, i, boxBlurKernel, N, &(imgOut.g[i*img.width]));
		simpleLineConv(img.b, img.width, img.height, 0, i, boxBlurKernel, N, &(imgOut.b[i*img.width]));
	}
  	salvar_imagem("cachorroBoxBlur.jpg", &imgOut);
	imgFree(&imgOut);

}
