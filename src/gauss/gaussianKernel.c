#include "gaussianKernel.h"


void gaussianSamples1D(float sd, int n_samples, float* sample_vec){
	int sample_interval = (int) (6*sd)/(n_samples-1);
	int i;
	float sample;
	for (i=-((n_samples-1)/2); i<=((n_samples-1)/2); i++){
		sample=i*((float)1/sqrt(2*M_PI*sd*sd))*exp(-((float)i*sample_interval/2*sd*sd));
		sample_vec[i]=sample;
	}
}

