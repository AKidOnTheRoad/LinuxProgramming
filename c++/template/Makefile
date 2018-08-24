
CXXFLAGS = -std=c++11 -Wall

.PHONY:all clean

all:box

box:box.o
	$(CXX) -o $@ $<

clean:
	@rm -rf box box.o
