#include "gaussianKernel.h"
#include <stdio.h>

int main(){
	float gaussVec[9];
	int i;
	gaussianSamples1D(0.9, 9, gaussVec);
	for (i=0; i< 9;i++){
		printf("%f,", gaussVec[i]);
	}
}
