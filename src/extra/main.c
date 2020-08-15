#include "linear_gauss.h"
#include "thread_gauss.h"
#include "cronometro.h"
#include <stdio.h>
#include <string.h>

#define ITERACOES 3

int main(){
	/*Variavel lixo para conseguir chamar a funcao medir_tempo,
	  como nenhuma das funcoes precisa de paramentros essa
	  variavel nao afeta em nada*/
	int lixo;
	
	for(int i=0; i<ITERACOES; i++){
		medir_tempo(linear_gauss, &lixo);
	}
	for(int i=0; i<ITERACOES; i++){
		medir_tempo(thread_gauss, &lixo);
	}
	return 0;
}
