CXX = g++
CXXFLAGS = -Wall -Werror -ansi -pedantic
LSFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
OBJ = NBody.o

all: NBody

NBody: NBody.o
	$(CXX) NBody.o -o NBody $(LSFMLFLAGS)

NBody.o: NBody.cpp NBody.hpp
	$(CXX) -c NBody.cpp $(CXXFLAGS)

clean:
	rm NBody $(OBJ) *~ *.gch -rf
