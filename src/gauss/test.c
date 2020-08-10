#include "gaussianKernel.h"
#include <stdio.h>

int main(){
	float gaussVec[30];
	int i;
	float acc;
	/*
	gaussianSamples1D(1, 30, gaussVec);
	for (i=0; i<30; i++){
		printf("%f\n", gaussVec[i]);
		acc+=gaussVec[i];
	}
	printf("area=%f\n", acc);
	*/
	float linear(float sd, float x){ return x;}
	float res = simpsonIntegration(linear, 0, 5, 8, 8);
	printf("%f\n", res);	
}
