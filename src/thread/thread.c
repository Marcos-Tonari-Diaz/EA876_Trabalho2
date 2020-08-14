/* Contador de palavras
 *
 * Este programa recebera uma serie de caracteres representando palavras em sua
 * entrada. Ao receber um caractere fim de linha ('\n'), deve imprimir na tela o
 * numero de palavras separadas que recebeu e, apos, encerrar.
 */
#include "thread.h"


void* worker(void *arg){
    /*thread
    pego a parametro, dou o typecast pra thread_args e calculo o primo do valor N do thread_args*/
     
    thread_args* work = (thread_args*)(arg);
    if(work->COLOR == RED){
        for (int i=0; i<(work->IMG.height); i++) {
            simpleLineConv(work->IMG.r, work->IMG.width, work->IMG.height, 0, i, work->FILTRO, work->N, &(imgOut.r[i*work->IMG.width]));
        }
    }else if(work->COLOR == GREEN){
        for (int i=0; i<(work->IMG.height); i++) {
            simpleLineConv(work->IMG.g, work->IMG.width, work->IMG.height, 0, i, work->FILTRO, work->N, &(imgOut.g[i*work->IMG.width]));
        }
    }else if(work->COLOR == BLUE){ 
        for (int i=0; i<(work->IMG.height); i++) {
            simpleLineConv(work->IMG.b, work->IMG.width, work->IMG.height, 0, i, work->FILTRO, work->N, &(imgOut.b[i*work->IMG.width]));
        }
    }
    free(work);
    return NULL;
}


void* thread_conv(void* args) {
    
    
    thread_args *red;
    thread_args *green;
    thread_args *blue;
    
    imagem img = abrir_imagem("../../data/cachorro.jpg");

    imgAlloc(&imgOut, img.width, img.height);

    int N = 8;
    float boxBlurKernel[N*N] ;
    for (int i=0; i<(N*N); i++){
        boxBlurKernel[i]=(float)1/((float)N*N);
    }
    
    red = (thread_args*)malloc(sizeof(thread_args));
    red->COLOR = RED;
    red->IMG = img;
    red->FILTRO = boxBlurKernel;
    red->N = N;
    pthread_create(&(workers[RED]), NULL, worker, (void*)red);


    green = (thread_args*)malloc(sizeof(thread_args));
    green->COLOR = GREEN;
    green->IMG = img;
    green->FILTRO = boxBlurKernel;
    green->N = N;
    pthread_create(&(workers[GREEN]), NULL, worker, (void*)green);


    blue = (thread_args*)malloc(sizeof(thread_args));
    blue->COLOR = BLUE;
    blue->IMG = img;
    blue->FILTRO = boxBlurKernel;
    blue->N = N;
    pthread_create(&(workers[BLUE]), NULL, worker, (void*)blue);
    
    

    for(int i=0; i<WORKER; i++){
        pthread_join(workers[i], NULL);
    }

    salvar_imagem("cachorro_thread.jpg", &imgOut);
    imgFree(&imgOut);
    return NULL;
}

