
CXXFLAGS = -Wall -std=c++11

.PHONY:all clean

all: init_list

init_list:init_list.o
	$(CXX) -o $@ $<

clean:
	@rm -rf init_list init_list.o

