
CXXFLAGS = -Wall -std=c++11
.PHONY: all clean

all:string string_cmp throw_str custom_throw

string:string.o
	$(CXX) -o $@ $<

string_cmp:string_cmp.o
	$(CXX) -o $@ $<

throw_str:throw_str.o
	$(CXX) -o $@ $<

custom_throw:custom_throw.o
	$(CXX) -o $@ $<

clean:
	@rm -rf string string.o
	@rm -rf string_cmp string_cmp.o
	@rm -rf throw_str throw_str.o
	@rm -rf custom_throw custom_throw.o
