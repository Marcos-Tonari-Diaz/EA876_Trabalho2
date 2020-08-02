#include <line_conv.h>

void imgAlloc(imagem* img, int width, int height){
	 img->r=(float*) malloc(width*height*sizeof(float));
	 img->g=(float*) malloc(width*height*sizeof(float));
	 img->b=(float*) malloc(width*height*sizeof(float));
	 img->width = width;
	 img->height = height;
}

void imgFree(imagem* img){
	free(img->r);
	free(img->g);
	free(img->b);
}

void simpleLineConv(float* channel, int width, int height, int startX, int startY, float* kernel, int N, float* lineOut){
	int i;
	int kx;
	int ky;
	int imgX;
	int imgY;
	int acumulador;
	// para todo pixel na linha
	for (i=startX; i<width; i++){
		acumulador=0;
		// para todo pixel do kernel
		for (ky=0; ky<N; ky++){
			for (kx=0; kx<N; kx++){
				imgX = i+1-kx;
				imgY = startY+1-ky;
				// zero padding
				if (imgX < 0 || imgX > (width-1)
				 || imgY < 0 || imgY > (height-1)){
					//nao faz nada (multiplicacao por 0)
				}
				else{
					acumulador+= 
					channel[imgY*width+imgX] * kernel[ky*N+kx];
				}
			}
		} 	
		// overflow de cor
		if (acumulador > 255) acumulador = 255;
		lineOut[i]=acumulador;
	}
	return; 
}
