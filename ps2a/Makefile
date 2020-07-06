CC = g++
CFLAGS = -c -Wall -Werror -pedantic
LFLAGS = -lboost_unit_test_framework
OBJ = LFSR.o test.o

all: ps2a

ps2a: LFSR.o test.o
	$(CC) -o ps2a $(OBJ) $(LFLAGS)

LFSR.o: LFSR.cpp LFSR.hpp
	$(CC) -c LFSR.cpp $(CFLAGS)

test.o: test.cpp LFSR.hpp
	$(CC) -c test.cpp $(CFLAGS)

clean:
	rm ps2a $(OBJ) *~ *.gch -rf
