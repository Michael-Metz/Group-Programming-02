#followed this make file tutorial
#http://mrbook.org/blog/tutorials/make/

#variable for the compiler
CC = g++

#tell the compile to use c++ 11 standard
CFLAGS = -std=c++11 -c

#run "make all" in the command line to compile all 3 programs
all: insertionsort shellsort mergesort

#insertion sort program
insertionsort: LinkedList.o InsertionSortDriver.o
	$(CC) LinkedList.o InsertionSortDriver.o -o insertionsort

InsertionSortDriver.o:
	$(CC) $(CFLAGS) InsertionSortDriver.cpp

LinkedList.o:
	$(CC) $(CFLAGS) LinkedList.cpp

#shell sort program
shellsort: ShellSortDriver.o
	$(CC) ShellSortDriver.o -o shellsort

ShellSortDriver.o:
	$(CC) $(CFLAGS) ShellSortDriver.cpp

#merge sort program
mergesort: MergeSortDriver.o
	$(CC) MergeSortDriver.o -o mergesort

MergeSortDriver.o:
	$(CC) $(CFLAGS) MergeSortDriver.cpp

clean:
	rm *.o

#clean and then compile
refresh: clean all
