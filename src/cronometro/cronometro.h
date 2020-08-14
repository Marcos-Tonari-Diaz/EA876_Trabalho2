#ifndef CRONOMETRO_H
#define CRONOMETRO_H
#include <time.h>
#include <sys/time.h>
#include <stdio.h>

void medir_tempo(void *(*funcao)(void *args), void *args);

#endif

