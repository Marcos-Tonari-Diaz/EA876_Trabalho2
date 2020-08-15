#include "thread.h"
#include "process.h"
#include "linear_box.h"
#include "cronometro.h"
#include <stdio.h>
#include <string.h>

#define ITERACOES 4


int main(){
	/*Variavel lixo para conseguir chamar a funcao medir_tempo,
	  como nenhuma das funcoes precisa de paramentros essa
	  variavel nao afeta em nada*/
	int lixo;

	printf("linear\n");
	for(int i=0; i<ITERACOES; i++){
		medir_tempo(linear_box, &lixo);
	}
	printf("thread\n");
	for(int i=0; i<ITERACOES; i++){
		medir_tempo(thread_conv, &lixo);
	}
	printf("processo\n");
	for(int i=0; i<ITERACOES; i++){
		medir_tempo(processo_conv, &lixo);
	}
	return 0;

}
