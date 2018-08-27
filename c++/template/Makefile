
CXXFLAGS = -std=c++11 -Wall

.PHONY:all clean

all:box arg

box:box.o
	$(CXX) -o $@ $<

arg:arg.o
	$(CXX) -o $@ $<
recusrse_arg:recusrse_arg.o
	$(CXX) -o $@ $<

clean:
	@rm -rf box box.o
	@rm -rf arg arg.o
	@rm -rf recusrse_arg recusrse_arg.o
