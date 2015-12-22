all: 
	@( (cd libindigoc; make) && \
	   (cd igo; make) && \
	   (cd igor; make) )

clean:
	@( (cd libindigoc; make clean) && \
	   (cd igo; make clean) && \
	   (cd igor; make clean) )

.PHONY: all clean
