
CXXFLAGS = -std=c++11 -Wall

.PHONY:all clean

all: shared_ptr new weak_ptr text

shared_ptr:shared_ptr.o
	$(CXX) -o $@ $<

new:new.o
	$(CXX) -o $@ $<

weak_ptr:weak_ptr.o
	$(CXX) -o $@ $<

new_array:new_array.o
	$(CXX) -o $@ $<

text:TextQuery.o
	$(CXX) -o $@ $<

clean:
	@rm -rf shared_ptr shared_ptr.o
	@rm -rf new new.o
	@rm -rf weak_ptr weak_ptr.o
	@rm -rf new_array new_array.o
	@rm -rf text TextQuery.o
