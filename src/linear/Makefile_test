all: sobel gauss box thread main

box:
	gcc -o box filtros/box_test.c ../images/imageprocessing.o ../conv/line_conv.o -I ../images -I ../conv -lfreeimage
sobel:
	gcc -g -o sobel filtros/sobel_test.c ../images/imageprocessing.o ../conv/line_conv.o -I ../images -I ../conv -lfreeimage -lm
gauss:
	gcc -o gauss linear_gauss.c ../images/imageprocessing.o ../conv/line_conv.o ../gauss/gaussianKernel.o -I ../images -I ../conv -lfreeimage -I ../gauss -lm
thread:
	gcc -o thread thread.c ../images/imageprocessing.o ../conv/line_conv.o -I ../images -I ../conv -lfreeimage -lpthread 

main:
	gcc -o main main.c 

clean:
	rm -f gauss box sobel
	rm -f *.jpg
test: all
	./sobel
	./gauss
	./box
	./thread
gcc -c thread.c -I ../images -I ../conv -lfreeimage -lpthread
gcc -c linear_box.c -I ../images -I ../conv  -lfreeimage
gcc -omain main.c ../images/imageprocessing.o ../conv/line_conv.o cronometro.o linear_box.o thread.o -I ../images -I ../conv -lfreeimage -lpthread
