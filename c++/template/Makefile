
CXXFLAGS = -std=c++11 -Wall

.PHONY:all clean

all:box arg recusrse_arg template_class template_overload

box:box.o
	$(CXX) -o $@ $<

arg:arg.o
	$(CXX) -o $@ $<

recusrse_arg:recusrse_arg.o
	$(CXX) -o $@ $<

non-type-template:non-type-template.o
	$(CXX) -o $@ $<

template_class:template_class.o
	$(CXX) -o $@ $<

template_overload:template_overload.o
	$(CXX) -o $@ $<

clean:
	@rm -rf box box.o
	@rm -rf arg arg.o
	@rm -rf recusrse_arg recusrse_arg.o
	@rm -rf non-type-template non-type-template.o
	@rm -rf template_class template_class.o
	@rm -rf template_overload template_overload.o
