#include "gaussianKernel.h"
#include <stdio.h>

int main(){
	int N=11;
	float gaussVec[N];
	int i;
	gaussianSamples1D(0.1, N, gaussVec);
	for (i=0; i<N; i++){
		printf("%f\n", gaussVec[i]);
	}
}
