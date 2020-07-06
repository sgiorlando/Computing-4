CXX = g++
CXXFLAGS = -g -Wall -Werror -ansi -pedantic
LSFMLFLAGS = -lsfml-system
OBJ = ED.o EditDistance.o

all: ED

ED: ED.o EditDistance.o
	$(CXX) ED.o EditDistance.o -o ED $(LSFMLFLAGS)

ED.o: ED.cpp EditDistance.hpp
	$(CXX) -c $< $(CXXFLAGS)

EditDistance.o: EditDistance.cpp EditDistance.hpp
	$(CXX) -c $< $(CXXFLAGS)

clean:
	rm ED EditDistance $(OBJ) *~ *.gch -rf
