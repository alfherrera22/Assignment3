#Declaring variables for the Makefile

CC=g++


CFLAGS=-c -Wall

all: tevent

tevent: a3.o
	$(CC) -pthread a3.cpp a3.h -o tevent

a3.o: a3.cpp
	$(CC) $(CFLAGS) a3.cpp

clean:
	rm -rf *o tevent
