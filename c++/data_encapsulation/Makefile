

.PHONY:all clean

all:data_encap

data_encap:data_encap.o
	$(CXX) -o $@ $<

clean:
	@rm -rf data_encap.o data_encap

