all: 
	@( (cd libindigo; make) && \
	   (cd igo; make) )

clean:
	@(cd libindigo; make clean) && \
	@(cd igo; make clean)

.PHONY: libindigo igo igor
