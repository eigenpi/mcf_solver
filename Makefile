CC=g++

CFLAGS=-O3 -Wall
LIBS=-lm -lstdc++

CSOURCES=$(wildcard *.cpp)
OBJECTS=$(patsubst %.cpp,%.o,${CSOURCES})

TARGETS=mcf_solver

all: ${TARGETS}

mcf_solver: ${OBJECTS}
	$(CC) $(CFLAGS) $(LIBS) -o $@ ${OBJECTS}

.cpp.o:
	$(CC) $(CFLAGS) -c $<
