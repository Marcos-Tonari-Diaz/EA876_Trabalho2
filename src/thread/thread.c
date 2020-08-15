#include "thread.h"


void* worker(void *arg){
    /*pego a parametro, dou o typecast pra thread_args*/
    thread_args* work = (thread_args*)(arg);

	/*Dependendo da cor passada aplico a convolucao da cor*/
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
    //iteracao atual	
    int iter = *((int*) args);

    
    /*Inicializo as threads para cada cor da imagem*/
    thread_args *red;
    thread_args *green;
    thread_args *blue;
    
    imagem img = abrir_imagem("data/cachorro.jpg");

    imgAlloc(&imgOut, img.width, img.height);
    /*crio o filtro*/
    int N = 8;
    float boxBlurKernel[N*N] ;
    for (int i=0; i<(N*N); i++){
        boxBlurKernel[i]=(float)1/((float)N*N);
    }
    
    /*Configuro as informacoes para fazer a convolucao inicio a thread para cada cor*/
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
    
    /*Espero todas as threads encerrarem*/
    for(int i=0; i<WORKER; i++){
        pthread_join(workers[i], NULL);
    }

    liberar_imagem(&img);
	if (iter==99)
    		salvar_imagem("resultados/cachorro_thread.jpg", &imgOut);
    imgFree(&imgOut);
    return NULL;
}

