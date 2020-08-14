
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

/*tipo pro thread ter a info do numero e o id*/
typedef struct{
    int COLOR;
    imagem IMG;
    float* FILTRO;
    int N;
    } thread_args;

/*Variaveis Globais*/

pthread_t workers[WORKER];//threads
imagem imgOut;

void* worker(void *arg);

void* thread_conv(void* args);
