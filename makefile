# makefile for LinkList Doubly Linked List
# Betty Phipps
# Date: 04/07/2025

#name of executable
main: main.o linklist.o
	g++ $(CXXFLAGS) main.o linklist.o -o main

main.o: main.cpp linklist.h
	g++ $(CXXFLAGS) -c main.cpp

linklist.o: linklist.cpp linklist.h
	g++ $(CXXFLAGS) -c linklist.cpp

clean:
	rm -rf *.o main

CXXFLAGS = -std=c++11 -Wall -Wextra

