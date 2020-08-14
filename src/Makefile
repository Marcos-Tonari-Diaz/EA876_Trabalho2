all:
	gcc -o main main.c images/imageprocessing.o conv/line_conv.o cronometro/cronometro.o linear/linear_box.o thread/thread.o -I images -I conv -I cronometro -I linear -I thread -lfreeimage -lpthread

test: all
	./main

clean:
	rm main
