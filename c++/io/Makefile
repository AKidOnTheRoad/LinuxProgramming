
CXXFLAGS = -std=c++11 -Wall

.PHONY:all clean

all:cin strstream forward_list

cin:cin.o
	$(CXX) -o $@ $<

strstream:strstream.o
	$(CXX) -o $@ $<

forward_list:forward_list.o
	$(CXX) -o $@ $<

vector:vector.o
	$(CXX) -o $@ $<

clean:
	@rm -rf cin cin.o
	@rm -rf strstream strstream.o
	@rm -rf forward_list forward_list.o
	@rm -rf vector vector.o
