all: sobel gauss box

box:
	gcc -o box box_test.c ../images/imageprocessing.o ../conv/line_conv.o -I ../images -I ../conv -lfreeimage
sobel:
	gcc -g -o sobel sobel_test.c ../images/imageprocessing.o ../conv/line_conv.o -I ../images -I ../conv -lfreeimage -lm
gauss:
	gcc -o gauss gaussian_test.c ../images/imageprocessing.o ../conv/line_conv.o ../gauss/gaussianKernel.o -I ../images -I ../conv -lfreeimage -I ../gauss -lm
clean:
	rm -f gauss box sobel
	rm -f *.jpg
test: all
	./sobel
	./gauss
	./box
