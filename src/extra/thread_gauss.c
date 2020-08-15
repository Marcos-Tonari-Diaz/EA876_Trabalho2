#include "thread_gauss.h"

void* worker(void *arg){
    /*pego a parametro, dou o typecast pra thread_args*/
    thread_args* work = (thread_args*)(arg);

	/*Dependendo da cor passada aplico a convolucao ao canal*/
    if(work->COLOR == RED){
        for (int i=0; i<(work->IMG.height); i++) {
            lineConvVerticalKernel(work->IMG.r, work->IMG.width, work->IMG.height, 0, i, work->FILTRO, work->N, &(imgTemp.r[i*work->IMG.width]));
        }
        for (int i=0; i<(work->IMG.height); i++) {
            lineConvHorizontalKernel(&(imgTemp.r[i*work->IMG.width]), work->IMG.width, work->IMG.height, 0, i, work->FILTRO, work->N, &(imgOut.r[i*work->IMG.width]));
        }
    }else if(work->COLOR == GREEN){
        for (int i=0; i<(work->IMG.height); i++) {
            lineConvVerticalKernel(work->IMG.g, work->IMG.width, work->IMG.height, 0, i, work->FILTRO, work->N, &(imgTemp.g[i*work->IMG.width]));
        }
        for (int i=0; i<(work->IMG.height); i++) {
            lineConvHorizontalKernel(&(imgTemp.g[i*work->IMG.width]), work->IMG.width, work->IMG.height, 0, i, work->FILTRO, work->N, &(imgOut.g[i*work->IMG.width]));
        }
    }else if(work->COLOR == BLUE){ 
        for (int i=0; i<(work->IMG.height); i++) {
            lineConvVerticalKernel(work->IMG.b, work->IMG.width, work->IMG.height, 0, i, work->FILTRO, work->N, &(imgTemp.b[i*work->IMG.width]));
        }
        for (int i=0; i<(work->IMG.height); i++) {
            lineConvHorizontalKernel(&(imgTemp.b[i*work->IMG.width]), work->IMG.width, work->IMG.height, 0, i, work->FILTRO, work->N, &(imgOut.b[i*work->IMG.width]));
        }
    }
    free(work);
    return NULL;
}


void* thread_gauss(void* args) {
    
    /*Inicializo as threads para cada cor da imagem*/
    thread_args *red;
    thread_args *green;
    thread_args *blue;
    
    imagem img = abrir_imagem("data/cachorro.jpg");
    imgAlloc(&imgOut, img.width, img.height);

    imagem imgTemp;
    imgAlloc(&imgTemp, img.width, img.height);

    int N = 50;
    float sd = 1;
    float gauss[N];
    gaussianSamples1D(sd, N, gauss);
    
	/*Configuro as informacoes para fazer a convolucao inicio a thread para cada cor*/
    red = (thread_args*)malloc(sizeof(thread_args));
    red->COLOR = RED;
    red->IMG = img;
    red->imgTemp = imgTemp;
    red->FILTRO = gauss;
    red->N = N;
    pthread_create(&(workers[RED]), NULL, worker, (void*)red);


    green = (thread_args*)malloc(sizeof(thread_args));
    green->COLOR = GREEN;
    green->IMG = img;
    green->imgTemp = imgTemp;
    green->FILTRO = gauss;
    green->N = N;
    pthread_create(&(workers[GREEN]), NULL, worker, (void*)green);


    blue = (thread_args*)malloc(sizeof(thread_args));
    blue->COLOR = BLUE;
    blue->IMG = img;
    blue->imgTemp = imgTemp;
    blue->FILTRO = gauss;
    blue->N = N;
    pthread_create(&(workers[BLUE]), NULL, worker, (void*)blue);
    
    
    /*Espero todas as threads encerrarem*/
    for(int i=0; i<WORKER; i++){
        pthread_join(workers[i], NULL);
    }

   /*Salvo a imagem*/
    salvar_imagem("cachorroThreadGauss.jpg", &imgOut);
    liberar_imagem(&img);
    imgFree(&imgOut);
    return NULL;
}

