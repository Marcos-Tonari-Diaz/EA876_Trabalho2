IMG=imageprocessing.c 
IMGO=$(IMG:.c=.o)
LINE_CONV=line_conv.c
LINE_CONVO=$(LINE_CONV:.c=.o)
LINEAR=linear_box.c
LINEARO=$(LINEAR:.c=.o)
THREAD=thread.c
THREADO=$(THREAD:.c=.o)


all: IMGO LINE_CONVO LINEARO THREADO PROCESSO CRONO
	$(MAKE) -C src

LINE_CONVO: IMGO
	$(MAKE) -C src/conv

IMGO:
	$(MAKE) -C src/images

LINEARO: LINE_CONVO 
	$(MAKE) -C src/linear

THREADO: LINE_CONVO
	$(MAKE) -C src/thread

PROCESSO: LINE_CONVO
	$(MAKE) -C src/process

CRONO: 
	$(MAKE) -C src/cronometro

clean:
	$(MAKE) clean -C src/conv
	$(MAKE) clean -C src/gauss
	$(MAKE) clean -C src/images
	$(MAKE) clean -C src/linear
	$(MAKE) clean -C src/thread
	$(MAKE) clean -C src/process
	$(MAKE) clean -C src/cronometro
	$(MAKE) clean -C src/extra
	$(MAKE) clean -C src
	rm -f resultados/*.jpg
	rm -f temp/*.pdf
	rm -f main


test: all
	./main | python3 src/analise.py	

gauss:
	$(MAKE) -C src/gauss

extra: gauss
	$(MAKE) -C src/extra
	./src/extra/gauss
	./src/extra/sobel
