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

	int N = 8;
	float boxBlurKernel[N*N] ;
	for (i=0; i<(N*N); i++){
		boxBlurKernel[i]=(float)1/((float)N*N);
	}

	float gaussianKernel3x3[3*3];
	gaussianKernel3x3[0]=1;
	gaussianKernel3x3[1]=2;
	gaussianKernel3x3[2]=1;
	gaussianKernel3x3[3]=2;
	gaussianKernel3x3[4]=4;
	gaussianKernel3x3[5]=2;
	gaussianKernel3x3[6]=1;
	gaussianKernel3x3[7]=2;
	gaussianKernel3x3[8]=1;
	
	for (i=0; i<(3*3); i++){
		gaussianKernel3x3[i]=((float)1/(float)16)*gaussianKernel3x3[i];
	}

	float altGaussianKernel3x3[3*3];
	altGaussianKernel3x3[0]=0.107035;
	altGaussianKernel3x3[1]=0.113092;
	altGaussianKernel3x3[2]=0.107035;
	altGaussianKernel3x3[3]=0.113092;
	altGaussianKernel3x3[4]=0.119491;
	altGaussianKernel3x3[5]=0.113092;
	altGaussianKernel3x3[6]=0.107035;
	altGaussianKernel3x3[7]=0.113092;
	altGaussianKernel3x3[8]=0.107035;
	
	float gaussianKernel5x5[5*5];
	gaussianKernel5x5[0]=1;
	gaussianKernel5x5[1]=4;
	gaussianKernel5x5[2]=6;
	gaussianKernel5x5[3]=4;
	gaussianKernel5x5[4]=1;
	gaussianKernel5x5[5]=4;
	gaussianKernel5x5[6]=16;
	gaussianKernel5x5[7]=24;
	gaussianKernel5x5[8]=16;
	gaussianKernel5x5[9]=4;
	gaussianKernel5x5[10]=6;
	gaussianKernel5x5[11]=24;
	gaussianKernel5x5[12]=36;
	gaussianKernel5x5[13]=24;
	gaussianKernel5x5[14]=6;
	gaussianKernel5x5[15]=4;
	gaussianKernel5x5[16]=16;
	gaussianKernel5x5[17]=24;
	gaussianKernel5x5[18]=16;
	gaussianKernel5x5[19]=4;
	gaussianKernel5x5[20]=1;
	gaussianKernel5x5[21]=4;
	gaussianKernel5x5[22]=6;
	gaussianKernel5x5[23]=4;
	gaussianKernel5x5[24]=1;
	for (i=0; i<(5*5); i++){
		gaussianKernel5x5[i]=((float)1/(float)256)*gaussianKernel5x5[i];
	}

	float edge3x3[9];
	edge3x3[0]=1;
	edge3x3[1]=0;
	edge3x3[2]=-1;
	edge3x3[3]=0;
	edge3x3[4]=0;
	edge3x3[5]=0;
	edge3x3[6]=-1;
	edge3x3[7]=0;
	edge3x3[8]=1;
  	
	N=5;
	for (i=0; i<(img.height); i++) {
		simpleLineConv(img.r, img.width, img.height, 0, i, gaussianKernel5x5, N, &(imgOut.r[i*img.width]));
		simpleLineConv(img.g, img.width, img.height, 0, i, gaussianKernel5x5, N, &(imgOut.g[i*img.width]));
		simpleLineConv(img.b, img.width, img.height, 0, i, gaussianKernel5x5, N, &(imgOut.b[i*img.width]));
	}
	imagem imgOut2;
	imgAlloc(&imgOut2, img.width, img.height);
	for (i=0; i<(img.height); i++) {
		simpleLineConv(imgOut.r, img.width, img.height, 0, i, gaussianKernel5x5, N, &(imgOut2.r[i*img.width]));
		simpleLineConv(imgOut.g, img.width, img.height, 0, i, gaussianKernel5x5, N, &(imgOut2.g[i*img.width]));
		simpleLineConv(imgOut.b, img.width, img.height, 0, i, gaussianKernel5x5, N, &(imgOut2.b[i*img.width]));
	}
  	salvar_imagem("cachorroEdge.jpg", &imgOut2);
	imgFree(&imgOut);
	imgFree(&imgOut2);

	return 0;
}
