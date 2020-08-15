all:
	gcc -o ../main main.c images/imageprocessing.o conv/line_conv.o cronometro/cronometro.o linear/linear_box.o thread/thread.o process/process.o -I images -I conv -I cronometro -I linear -I thread -I process -lfreeimage -lpthread


clean:
	rm -f main
	rm -f *.jpg
