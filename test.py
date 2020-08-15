import numpy as np
import matplotlib.pyplot as plt
import sys

ITERACOES =3
for line in sys.stdin:
<<<<<<< HEAD
	try:
		print(float(line))
	except ValueError:
		sys.stdout.write(line)
		
=======
    print(line)
>>>>>>> 12b16fdfd4725a4a42a882b87362feb261c2e80a
