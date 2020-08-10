#include "gaussianKernel.h"
#include <stdio.h>


float simpsonIntegration(float(*F)(float sd, float x), float sd, float min, float max, int n_intervals){
	float h = (max - min)/(n_intervals);
	float sum=0;
	int i;
	for (i=0; i< (n_intervals)-1; i+=2){
		sum+=
		(*F)(sd, min+i*h) +
		4*(*F)(sd, min+(i+1)*h) +
		(*F)(sd, min+(i+2)*h);
	}
	return h/3*sum;	
}

float gaussianDistribution(float sd, float x){
	return ((float)1/sqrt(2*M_PI*sd*sd))*exp(-(x*x)/2*sd*sd);
}

void gaussianSamples1D(float sd, int n_samples, float* sample_vec){
	float sample_interval = (float) (6*sd)/(n_samples-1); 
	float area=0;
	float increment=0;
	int i;
	int index;
	float sample;
	//toma uma amostra da distribuicao gaussiana em multiplos de sample_interval
	for (i=-((n_samples-1)/2); i<=((n_samples-1)/2); i++){
		index = i+((n_samples-1)/2);
		sample_vec[index]=
		area+=sample_vec[index];
	}
	// normalizar as amostras pela area (tornar a area=1)
	for (i=0; i<n_samples; i++){
		sample_vec[i]/=area;
	}
}


