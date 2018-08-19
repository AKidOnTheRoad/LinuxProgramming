
CXXFLAGS = -std=c++11 -Wall

.PHONY:all clean

all:stdio funobj child

stdio:stdio.o
	$(CXX) -o $@ $<

funobj:funobj.o
	$(CXX) -o $@ $<

child:child.o
	$(CXX) -o $@ $<

clean:
	@rm -rf stdio stdio.o
	@rm -rf funobj funobj.o
	@rm -rf child child.o
