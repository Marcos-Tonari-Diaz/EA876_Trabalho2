
#include "thread.h"
#include "linear_box.h"
#include "cronometro.h"
#include <stdio.h>
#include <string.h>

#define ITERACOES 100


int main(){
	int oi;
	printf("Tempo linear\n");
	medir_tempo(linear_box, &oi);
	printf("Tempo thread\n");
	medir_tempo(thread_conv, &oi);
	
	return 0;

}
