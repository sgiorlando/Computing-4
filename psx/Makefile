CC = g++
CFLAGS = -c -Wall -Werror --pedantic
LFLAGS = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
OBJ = sierpinski.o original.o

all: sierpinski original

sierpinski: sierpinski.o
	$(CC) sierpinski.o -o sierpinski $(LFLAGS)

sierpinski.o: sierpinski.cpp sierpinski.hpp
	$(CC) -c sierpinski.cpp $(CFLAGS)

original: original.o
	$(CC) original.o -o original $(LFLAGS)

original.o: original.cpp original.hpp
	$(CC) -c original.cpp $(CFLAGS)

clean:
	rm sierpinski original $(OBJ) *~ *.gch -rf
