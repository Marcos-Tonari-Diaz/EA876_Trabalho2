#include "thread.h"
#include "process.h"
#include "linear_box.h"
#include "cronometro.h"
#include <stdio.h>
#include <string.h>

#define ITERACOES 100 

int main(){
	for(int i=0; i<ITERACOES; i++){
		medir_tempo(linear_box, (void*)&i);
	}
	for(int i=0; i<ITERACOES; i++){
		medir_tempo(thread_conv,(void*) &i);
	}
	// OBS: necessario esvaziar o stdout (fflush) antes de chamar fork()
	// pois ele copia tambem os File Descriptors e, desse modo, 
	// parece retornar para o inicio do buffer circular no pipe
	fflush(stdout);
	for(int i=0; i<ITERACOES; i++){
		medir_tempo(processo_conv,(void*) &i);
		fflush(stdout);
	}
	return 0;
}
