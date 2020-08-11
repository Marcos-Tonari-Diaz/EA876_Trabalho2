#include <math.h>

void gaussianSamples1D(float sd, int n_samples, float* sample_vec);
float simpsonIntegration(float(*F)(float, float), float sd, float min, float max, int n_intervals);
float gaussianDistribution(float sd, float x);
