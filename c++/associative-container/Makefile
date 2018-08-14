
CXXFLAGS = -std=c++11 -Wall

.PHONY:all clean

all:family insert find

family:family.o
	$(CXX) -o $@ $<

insert:insert.o
	$(CXX) -o $@ $<

find:find.o
	$(CXX) -o $@ $<

clean:
	@rm -rf family family.o
	@rm -rf find find.o
	@rm -rf insert insert.o
