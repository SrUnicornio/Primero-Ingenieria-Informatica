
CXX = g++
CXXFLAGS = -std=c++17 -Wall
LDFLAGS =

files = *cc

all: Programa

Programa: $(files)
	@$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)


.PHONY: all clean

clean : 
	rm -f *.o Programa doc
	rm -rf *~ basura b i
	rm -rf a.out
	find . -name '*~' -exec rm {} \;
	find . -name basura -exec rm {} \;
