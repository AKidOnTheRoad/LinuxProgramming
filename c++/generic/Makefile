
CXXFLAGS = -std=c++11 -Wall

.PHONY:all clean

all: count string_count elimDups lambda stream_iterator

count:count.o
	$(CXX) -o $@ $<

string_count:string_count.o
	$(CXX) -o $@ $<

elimDups:elimDups.o
	$(CXX) -o $@ $<

lambda:lambda.o
	$(CXX) -o $@ $<

stream_iterator:stream_iterator.o
	$(CXX) -o $@ $<

clean:
	@rm -rf count count.o
	@rm -rf string_count string_count.o
	@rm -rf elimDups elimDups.o
	@rm -rf lambda lambda.o
	@rm -rf stream_iterator stream_iterator.o
