
CXXFLAGS = -std=c++11 -Wall
.PHONY:all clean

all:for_auto

for_auto:for_auto.o
	$(CXX) -o $@ $<

mult_array:mult_arrays.o
	$(CXX) -o $@ $<

clean:
	@rm -rf for_auto for_auto.o
	@rm -rf mult_array mult_arrays.o
