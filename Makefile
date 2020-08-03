IMG=imageprocessing.c 
IMGO=$(IMG:.c=.o)
LINE_CONV=line_conv.c
LINE_CONVO=$(LINE_CONV:.c=.o)


test:
$(MAKE) -C src/tests

LINE_CONVO: IMG0
    $(MAKE) -C src/conv

IMG0:
    $(MAKE) -C src/images
