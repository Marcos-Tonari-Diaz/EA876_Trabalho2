#ifndef TESTS
#define TESTS

#include <line_conv.h>
#include <imageprocessing.h>
#include <gaussianKernel.h>

#endif

int main(){
	int i;
	imagem img;
	img = abrir_imagem("../../data/cachorro.jpg");
       	
	imagem imgOut;
	imgAlloc(&imgOut, img.width, img.height);
	imagem imgTemp;
	imgAlloc(&imgTemp, img.width, img.height);

	int N = 50;
	float sd = 1;
	float gauss[N];
	gaussianSamples1D(sd, N, gauss);

	for (i=0; i<(img.height); i++) {
		lineConvVerticalKernel(img.r, img.width, img.height, 0, i, gauss, N, &(imgTemp.r[i*img.width]));
		lineConvVerticalKernel(img.g, img.width, img.height, 0, i, gauss, N, &(imgTemp.g[i*img.width]));
		lineConvVerticalKernel(img.b, img.width, img.height, 0, i, gauss, N, &(imgTemp.b[i*img.width]));
	}
	for (i=0; i<(img.height); i++) {

		lineConvHorizontalKernel(imgTemp.r, img.width, img.height, 0, i, gauss, N, &(imgOut.r[i*img.width]));
		lineConvHorizontalKernel(imgTemp.g, img.width, img.height, 0, i, gauss, N, &(imgOut.g[i*img.width]));
		lineConvHorizontalKernel(imgTemp.b, img.width, img.height, 0, i, gauss, N, &(imgOut.b[i*img.width]));
	}
  	salvar_imagem("cachorroTrueGauss.jpg", &imgOut);
	imgFree(&imgOut);
	imgFree(&imgTemp);

	return 0;
}
