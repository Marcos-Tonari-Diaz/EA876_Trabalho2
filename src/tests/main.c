
#include "thread.h"
#include "linear_box.h"
#include "cronometro.h"
#include <stdio.h>

#define ITERACOES 100
int main(){
	int i=0;
	printf("linear\n");
	medir_tempo(linear_box);
	printf("thread\n");
	medir_tempo(thread_conv);
	return 0;

}
