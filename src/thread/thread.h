
#ifndef THREAD 
#define THREAD

#include <stdlib.h>
#include <pthread.h>
#include <imageprocessing.h>
#include <line_conv.h>
//#include <gaussianKernel.h>

#endif

#define WORKER 3
#define ATIVO 1
#define INATIVO 0

enum color
{ 
    RED, 
    GREEN, 
    BLUE 
};

/*tipo pro thread ter a info da cor(rgb), a imagem, o tipo de filtro e o tamanho do filtro*/
typedef struct{
    int COLOR;
    imagem IMG;
    float* FILTRO;
    int N;
    } thread_args;

/*Variaveis Globais*/

pthread_t workers[WORKER];//threads
imagem imgOut;

/*funcao que faz a convolucao de cada cor em diferentes threads*/
void* worker(void *arg);

/*funcao que inicializa as threads e faz a convolucao*/
void* thread_conv(void* args);
