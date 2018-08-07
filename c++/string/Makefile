
CXXFLAGS = -Wall -std=c++11
.PHONY: all clean

all:string

string:string.o
	$(CXX) -o $@ $<

string_cmp:string_cmp.o
	$(CXX) -o $@ $<

clean:
	@rm -rf string string.o
	@rm -rf string_cmp string_cmp.o
