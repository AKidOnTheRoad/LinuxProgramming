
CXXFLAGS = -Wall -std=c++11

.PHONY:all clean

all: init_list static_member

init_list:init_list.o
	$(CXX) -o $@ $<


static_member:static_member.o
	$(CXX) -o $@ $<

constructor:constructor.o
	$(CXX) -o $@ $<

clean:
	@rm -rf init_list init_list.o
	@rm -rf static_member static_member.o
	@rm -rf constructor constructor.o



