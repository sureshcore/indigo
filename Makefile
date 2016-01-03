all: 
	@( (cd libindigoc; $(MAKE) ) && \
	   (cd igo; $(MAKE) ) && \
	   (cd igor; $(MAKE) ) )

clean:
	@( (cd libindigoc; make clean) && \
	   (cd igo; make clean) && \
	   (cd igor; make clean) )

.PHONY: all clean
