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

	int N = 5;
	float sd = 1;
	float gauss_vert[N];
	float gauss_horiz[N];
	gaussianSamples1D(sd, N, gauss_vert);
	gaussianSamples1D(sd, N, gauss_horiz);

	for (i=0; i<(img.height); i++) {
		lineConvVerticalKernel(img.r, img.width, img.height, 0, i, gauss_vert, N, &(imgOut.r[i*img.width]));
		lineConvVerticalKernel(img.g, img.width, img.height, 0, i, gauss_vert, N, &(imgOut.g[i*img.width]));
		lineConvVerticalKernel(img.b, img.width, img.height, 0, i, gauss_vert, N, &(imgOut.b[i*img.width]));
	}
  	salvar_imagem("cachorroTrueGauss.jpg", &imgOut);
	imgFree(&imgOut);

	return 0;
}
