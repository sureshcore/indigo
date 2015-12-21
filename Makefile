all: 
	@( (cd libindigoc; make) && \
	   (cd igo; make) )

clean:
	@( (cd libindigoc; make clean) && \
	   (cd igo; make clean) )

.PHONY: all clean
