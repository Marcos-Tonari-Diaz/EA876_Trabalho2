gaussianTest: gaussianKernel
	gcc -g -o linear_gauss linear_gauss.c ../images/imageprocessing.o ../conv/line_conv.o ./gaussianKernel.o -I ../images -I ../conv -I ./ -lm -lfreeimage

gaussianKernel:
	gcc -c gaussianKernel.c -I ./ -lm
clean:
	rm -f gaussianKernel.o
	rm -f linear_gauss

