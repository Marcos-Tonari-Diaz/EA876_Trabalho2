#ifndef CONVH 
#define CONVH

#include <imageprocessing.h>
#include <stdlib.h>

#endif

// Retorna uma linha da convolucao do canal com o kernel NxN
// A linha comeca no pixel start
// N pode variar de 3 a 7
// imgOut: ponteiro para espaco temporario da saida
// kernel: RowMajor (valores de uma mesma linha sao adjacentes)
void simpleLineConv(float* channel, int width, int height, int startX, int startY, float* kernel, int N, float* lineOut);

// retorna ponteiro para espaco temporario da imagem convoluida
void imgAlloc(imagem* img, int width, int height);

// libera o espaco temporario da imagem
void imgFree(imagem* img);
