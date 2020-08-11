#include <stdio.h>
#include "gaussianKernel.h"

// integracao numerica em um intervalo 
float simpsonIntegration(float(*F)(float, float), float sd, float min, float max, int n_intervals){
	float h = (max - min)/(n_intervals);
	float sum=0;
	int i;
	for (i=0; i< (n_intervals)-1; i+=2){
		sum+=
		F(sd, min+i*h) +
		4*F(sd, min+(i+1)*h) +
		F(sd, min+(i+2)*h);
	}
	return (h/3)*sum;	
}

// distribuicao gaussiana 
float gaussianDistribution(float sd, float x){
	return ((float)1)/sqrt(2*M_PI*sd*sd)*exp(-((float)x*x)/(2*sd*sd));
}

// produz um vetor com distribuicao gaussiana
void gaussianSamples1D(float sd, int n_samples, float* sample_vec){
	// n_samples sempre deve ser par
	float sample_interval = ((float)5)/(n_samples-1); 
	float used_area=0;
	int i;
	int index;
	float sample, min, max;
	//toma uma amostra da distribuicao gaussiana em multiplos de sample_interval
	for (i=-((n_samples-1)/2); i<=((n_samples-1)/2); i++){
		index = i+((n_samples-1)/2);
		min = i*sample_interval-sample_interval/2;
		max = i*sample_interval+sample_interval/2;
		sample_vec[index]=simpsonIntegration(gaussianDistribution, sd, min, max, 4);
		used_area+=sample_vec[index];
	}
	// normalizar as amostras pela area (tornar a area=1)
	for (i=0; i<n_samples; i++){
		sample_vec[i]/=used_area;
	}
}
