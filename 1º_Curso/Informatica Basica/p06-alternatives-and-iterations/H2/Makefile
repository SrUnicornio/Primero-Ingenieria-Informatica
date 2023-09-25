Cxx = g++
CxxFLAGS = -std=c++17 -Wall
LDFLAGS =

all: Harmonical2

Harmonical2: Harmonical2.o
        $(CXX) $(CXFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: all clean
        $(CXX) $(CXXFLAGS) -c $<
clean :
	rm -f *.o Harmonical2 doc
	rm -rf *~ basura b i
	rm -rf a.out
	find . -name '*~' -exec rm {} \;
	find . -name basura -exec rm {} \;

