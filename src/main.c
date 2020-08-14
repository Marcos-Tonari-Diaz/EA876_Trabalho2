
#include "thread.h"
#include "linear_box.h"
#include "cronometro.h"
#include <stdio.h>
#include <string.h>

#define ITERACOES 100


int main(){
	/*Variavel lixo para conseguir chamar a funcao medir_tempo,
	  como nenhuma das funcoes precisa de paramentros essa
	  variavel nao afeta em nada*/
	int lixo;

	printf("Tempo linear\n");
	medir_tempo(linear_box, &lixo);
	printf("Tempo thread\n");
	medir_tempo(thread_conv, &lixo);
	printf("Tempo processo\n");
	//medir_tempo(processo_conv, &lixo);
	
	return 0;

}
