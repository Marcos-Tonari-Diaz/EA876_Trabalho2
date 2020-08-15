import numpy as np
import matplotlib.pyplot as plt
import sys

ITERACOES = 100

linear = np.zeros(shape=(ITERACOES, 1))
thread = np.zeros(shape=(ITERACOES, 1))
processo = np.zeros(shape=(ITERACOES, 1))
linha = 0

#print("Iniciou a anlise!")

for line in sys.stdin:
    if(linha < ITERACOES):
        linear[linha-1] = float(line)
    elif(ITERACOES <= linha < 2*ITERACOES):
        thread[linha-ITERACOES] = float(line)
    elif(2*ITERACOES <= linha < 3*ITERACOES):
        processo[linha-(2*ITERACOES)] = float(line)
    linha+=1
n_bins = 20


lin = plt.figure(figsize=(10,10))
plt.hist(linear, bins=n_bins)
plt.xlabel("Tempo[s] \n Média = {}\nDesvio padrão = {}".format(np.mean(linear), np.std(linear)), fontsize=15)
plt.title("Tempo Linear", fontsize=15)

thre = plt.figure(figsize=(10,10))
plt.hist(thread, bins=n_bins)
plt.xlabel("Tempo[s] \n Média = {}\nDesvio padrão = {}".format(np.mean(thread), np.std(thread)), fontsize=15)
plt.title("Tempo em Threads", fontsize=15)

pro = plt.figure(figsize=(10,10))
plt.hist(processo, bins=n_bins)
plt.xlabel("Tempo[s] \n Média = {}\nDesvio padrão = {}".format(np.mean(processo), np.std(processo)), fontsize=15)
plt.title("Tempo em Processos", fontsize=15)

#plt.show()

lin.savefig("doc/linear.pdf", bbox_inches='tight')
thre.savefig("doc/thread.pdf", bbox_inches='tight')
pro.savefig("doc/processos.pdf", bbox_inches='tight')

