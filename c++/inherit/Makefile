
CXX = g++
CXXFLAGS = -std=c++11 -Wall

.PHONY:all clean

all:virtual_inherit

virtual_inherit:virtual_inherit.o
	$(CXX) -o $@ $<

clean:
	@rm -rf virtual_inherit virtual_inherit.o
