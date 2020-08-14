import numpy as np
import matplotlib as plt
import sys

ITERACOES = 100

linear = np.zeros(shape=(ITERACOES, 1))
thread = np.zeros(shape=(ITERACOES, 1))
processo = np.zeros(shape=(ITERACOES, 1))
linha = 0

for line in sys.stdin:
	if(linha > 0 and linha <=ITERACOES):
		linear[linha-1] = float(line)
	elif(linha<=ITERACOES+2 and linha <= (2*ITERACOES+1)):
		thread[linha-ITERACOES-2] = float(line)
	elif(linha<=(2*ITERACOES+3)):
		processo[linha-(2*ITERACOES)-3] = float(line)
	linha+=1


