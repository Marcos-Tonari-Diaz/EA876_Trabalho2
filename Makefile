IMG=imageprocessing.c 
IMGO=$(IMG:.c=.o)
LINE_CONV=line_conv.c
LINE_CONVO=$(LINE_CONV:.c=.o)
LINEAR=linear_box.c
LINEARO=$(LINEAR:.c=.o)
THREAD=thread.c
THREADO=$(THREAD:.c=.o)


all: IMGO GAUSS LINE_CONVO LINEARO THREADO
	$(MAKE) -C src

GAUSS: 
	$(MAKE) -C src/gauss

LINE_CONVO: IMGO
	$(MAKE) -C src/conv

IMGO:
	$(MAKE) -C src/images

LINEARO: LINE_CONVO 
	$(MAKE) -C src/linear

THREADO: LINE_CONVO
	$(MAKE) -C src/thread

clean:
	$(MAKE) clean -C src/conv
	$(MAKE) clean -C src/gauss
	$(MAKE) clean -C src/images
	$(MAKE) clean -C src/linear
	$(MAKE) clean -C src/thread
	$(MAKE) clean -C src
	rm -f *.jpg

test: all
	$(MAKE) test -C src
