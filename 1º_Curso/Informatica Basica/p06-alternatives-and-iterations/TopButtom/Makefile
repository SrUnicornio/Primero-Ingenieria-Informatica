Cxx = g++
CxxFLAGS = -std=c++17 -Wall
LDFLAGS = 

all: TopToButtom

TopToButtom: TopToBottom.o
	$(CXX) $(CXFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: all clean
	$(CXX) $(CXXFLAGS) -c $<
clean :
	rm -f *.o TopToBottom doc
	rm -rf *~ basura b i
	rm -rf a.out
	find . -name '*~' -exec rm {} \;
	find . -name basura -exec rm {} \;
