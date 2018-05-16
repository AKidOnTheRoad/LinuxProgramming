

.PHONY:clean

all:target basename nftw

target:getopt.o
	${CC} -o $@ $< 

basename:basename.o
	${CC} -o $@ $<

nftw:nftw.o
	${CC} -o $@ $<

func:
	${call demo_func,12,34,56}

define demo_func
	echo $0 $1 $2
endef

clean:
	@rm -rf getopt.o
	@rm -rf target
	@rm -rf basename.o
	@rm -rf basename
	@rm -rf nftw.o nftw
