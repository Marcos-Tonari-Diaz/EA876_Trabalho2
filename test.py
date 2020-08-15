import numpy as np
import matplotlib.pyplot as plt
import sys

ITERACOES =3

for line in sys.stdin:
	try:
		print(float(line))
	except ValueError:
		sys.stdout.write(line)
		
