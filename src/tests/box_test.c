#ifndef IMAGE_LIB
#define IMAGE_LIB

#include <line_conv.h>
#include <imageprocessing.h>

#endif

int main(){
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
  	
	for (i=0; i<(img.height); i++) {
		simpleLineConv(img.r, img.width, img.height, 0, i, boxBlurKernel, N, &(imgOut.r[i*img.width]));
		simpleLineConv(img.g, img.width, img.height, 0, i, boxBlurKernel, N, &(imgOut.g[i*img.width]));
		simpleLineConv(img.b, img.width, img.height, 0, i, boxBlurKernel, N, &(imgOut.b[i*img.width]));
	}
  	salvar_imagem("cachorroBoxBlur.jpg", &imgOut);
	imgFree(&imgOut);

	return 0;
}
