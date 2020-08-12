IMG=imageprocessing.c 
IMGO=$(IMG:.c=.o)
LINE_CONV=line_conv.c
LINE_CONVO=$(LINE_CONV:.c=.o)


all: IMG0 GAUSS LINE_CONVO
	$(MAKE) -C src/tests

GAUSS: 
	$(MAKE) -C src/gauss

LINE_CONVO: IMG0
	$(MAKE) -C src/conv

IMG0:
	$(MAKE) -C src/images

clean:
	$(MAKE) clean -C src/conv
	$(MAKE) clean -C src/gauss
	$(MAKE) clean -C src/images
