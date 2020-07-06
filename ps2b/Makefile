CC = g++
CFLAGS = -c -Wall -Werror -ansi -pedantic
LFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
OBJ = LFSR.o PhotoMagic.o

all: PhotoMagic

PhotoMagic: LFSR.o PhotoMagic.o
	$(CC) -o PhotoMagic $(OBJ) $(LFLAGS)

LFSR.o: LFSR.cpp LFSR.hpp
	$(CC) -c LFSR.cpp $(CFLAGS)

PhotoMagic.o: PhotoMagic.cpp LFSR.hpp
	$(CC)  -c PhotoMagic.cpp $(CLFAGS)

clean:
	rm PhotoMagic $(OBJ) *~ *.gch -rf
