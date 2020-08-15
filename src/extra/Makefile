all: sobel gauss

gauss: 
	gcc -o gauss linear_gauss.c ../gauss/gaussianKernel.o ../images/imageprocessing.o ../conv/line_conv.o -I ../images -I ../conv -I ../gauss -lfreeimage -lm
sobel:
	gcc -o sobel sobel_test.c ../images/imageprocessing.o ../conv/line_conv.o -I ../images -I ../conv -lfreeimage -lm

clean:
	rm -f gauss
	rm -f sobel
	rm -f *.jpg
