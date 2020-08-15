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
	
	for(int i=0; i<ITERACOES; i++){
		medir_tempo(linear_box, &lixo);
	}
	for(int i=0; i<ITERACOES; i++){
		medir_tempo(thread_conv, &lixo);
	}
	// OBS: necessario esvaziar o stdout (fflush) antes de chamar fork()
	// pois ele copia tambem os File Descriptors e, desse modo, 
	// parece retornar para o inicio do buffer circular no pipe
	fflush(stdout);
	for(int i=0; i<ITERACOES; i++){
		medir_tempo(processo_conv, &lixo);
		fflush(stdout);
	}
	return 0;
}
