all: linear gauss

linear:
	gcc -o linear linear.c ../images/imageprocessing.o ../conv/line_conv.o -I ../images -I ../conv -lfreeimage
gauss:
	gcc -o gauss gaussian_test.c ../images/imageprocessing.o ../conv/line_conv.o ../gauss/gaussianKernel.o -I ../images -I ../conv -lfreeimage -I ../gauss -lm
clean:
	rm gaussian linear
