#include "thread.h"
#include "process.h"
#include "linear_box.h"
#include "cronometro.h"
#include <stdio.h>
#include <string.h>

#define ITERACOES 5

int main(){
	/*Variavel lixo para conseguir chamar a funcao medir_tempo,
	  como nenhuma das funcoes precisa de paramentros essa
	  variavel nao afeta em nada*/
	int lixo;
	//FILE *testOut;
	//testOut = fopen("out.txt", "a");
	char out1[20];
	char out2[20];
	char out3[20];

	printf("linear\n");
	for(int i=0; i<ITERACOES; i++){
		medir_tempo(linear_box, &lixo, out1);
		//fprintf(testOut, "%s", out1);
	}
	printf("thread\n");
	for(int i=0; i<ITERACOES; i++){
		medir_tempo(thread_conv, &lixo, out2);
		//fprintf(testOut, "%s", out2);
	}
	printf("processo\n");
	fflush(stdout);
	for(int i=0; i<ITERACOES; i++){
		medir_tempo(processo_conv, &lixo, out3);
		fflush(stdout);
		//fprintf(testOut, "%s", out3);
	}
	//printf("%s%s%s", out1, out2, out3);
	return 0;
}
