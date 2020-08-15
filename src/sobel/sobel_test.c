#ifndef IMAGE_LIB
#define IMAGE_LIB

#include <line_conv.h>
#include <imageprocessing.h>
#include <math.h>
#endif

int main(){
	int i, j;
	imagem img;
	img = abrir_imagem("../../data/cachorro.jpg");
       	
	imagem Gx;
	imgAlloc(&Gx, img.width, img.height);
	imagem Gy;
	imgAlloc(&Gy, img.width, img.height);
	imagem GxTemp;
	imgAlloc(&GxTemp, img.width, img.height);
	imagem GyTemp;
	imgAlloc(&GyTemp, img.width, img.height);
	imagem imgOut;
	imgAlloc(&imgOut, img.width, img.height);

	//decomposicao do operador de sobel: op = averaging*differentiation
	float averaging[3]={1,2,1}; 
	float differentiation[3]={1,0,-1}; 
  	
	for (i=0; i<(img.height); i++) {
		lineConvHorizontalKernel(img.r, img.width, img.height, 0, i, differentiation, 3, &(GxTemp.r[i*img.width]));
		lineConvHorizontalKernel(img.g, img.width, img.height, 0, i, differentiation, 3, &(GxTemp.g[i*img.width]));
		lineConvHorizontalKernel(img.b, img.width, img.height, 0, i, differentiation, 3, &(GxTemp.b[i*img.width]));
		
		lineConvHorizontalKernel(img.r, img.width, img.height, 0, i, averaging, 3, &(GyTemp.r[i*img.width]));
		lineConvHorizontalKernel(img.g, img.width, img.height, 0, i, averaging, 3, &(GyTemp.g[i*img.width]));
		lineConvHorizontalKernel(img.b, img.width, img.height, 0, i, averaging, 3, &(GyTemp.b[i*img.width]));
	}
	for (i=0; i<(img.height); i++) {
		lineConvVerticalKernel(GxTemp.r, img.width, img.height, 0, i, averaging, 3, &(Gx.r[i*img.width]));
		lineConvVerticalKernel(GxTemp.g, img.width, img.height, 0, i, averaging, 3, &(Gx.g[i*img.width]));
		lineConvVerticalKernel(GxTemp.b, img.width, img.height, 0, i, averaging, 3, &(Gx.b[i*img.width]));

		lineConvVerticalKernel(GyTemp.r, img.width, img.height, 0, i, differentiation, 3, &(Gy.r[i*img.width]));
		lineConvVerticalKernel(GyTemp.g, img.width, img.height, 0, i, differentiation, 3, &(Gy.g[i*img.width]));
		lineConvVerticalKernel(GyTemp.b, img.width, img.height, 0, i, differentiation, 3, &(Gy.b[i*img.width]));
	}

	// G = sqrt(Gx^2+Gy^2)
	for(i=0; i<img.height; i++){
		for(j=0; j<img.width; j++){
			imgOut.r[i*img.width+j] = sqrt(Gx.r[i*img.width+j]*Gx.r[i*img.width+j]+
							Gy.r[i*img.width+j]*Gy.r[i*img.width+j]);
			imgOut.g[i*img.width+j] = sqrt(Gx.g[i*img.width+j]*Gx.g[i*img.width+j]+
							Gy.g[i*img.width+j]*Gy.g[i*img.width+j]);
			imgOut.b[i*img.width+j] = sqrt(Gx.b[i*img.width+j]*Gx.b[i*img.width+j]+
							Gy.b[i*img.width+j]*Gy.b[i*img.width+j]);
		}
	}
  	salvar_imagem("cachorroSobel.jpg", &imgOut);
	imgFree(&imgOut);
	imgFree(&Gx);
	imgFree(&Gy);
	imgFree(&GxTemp);
	imgFree(&GyTemp);

	return 0;
}
