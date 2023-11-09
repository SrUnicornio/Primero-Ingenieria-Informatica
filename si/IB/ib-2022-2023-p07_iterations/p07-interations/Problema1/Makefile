
CXX = g++
CXXFLAGS = -std=c++17 -Wall
LDFLAGS =

files = *cc

all: Programa

Programa: $(files)
	@$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)


.PHONY: all clean

clean : 
	@echo "cleaning up the directory..."
	@rm -rf *.o *gch *.out programa

