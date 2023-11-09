# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Informática Básica
#
# @author F. de Sande
# @date Dec 17 2022
# @brief A Makefile for the ChessPiece class code
# 

CXX = g++						                              # The C++ compiler command
#CXXFLAGS = -std=c++17 -g -Wall -pedantic -Weffc++ # The C++ compiler options (C++14, preserve debug symbols and warn all)
CXXFLAGS = -g -Wall -pedantic -Weffc++ -std=c++17 
LDFLAGS =						                              # The linker options (if any)

# The all target builds all of the programs handled by the makefile.
all: automatons

automatons: transition.h state.h automaton.h automaton.o automatons.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Indicate that the all and clean targets do not
# correspond to actual files.
.PHONY: all clean

# The following rule is effectively built into make and
# therefore need not be explicitly specified:
# hello_world.o: hello_world.cc
#
	$(CXX) $(CXXFLAGS) -c $<

# The clean target removes all of the executable files
# and object files produced by the build process
# We can use it for additional housekeeping purposes
clean :
	rm -f *.o automatons doc
	rm -rf *~ basura b i
	rm -rf a.out
	find . -name '*~' -exec rm {} \;
	find . -name basura -exec rm {} \;
