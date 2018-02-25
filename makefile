#followed this make file tutorial
#http://mrbook.org/blog/tutorials/make/

#variable for the compiler
CC = g++

CFLAGS = -std=c++11 -c

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
	rm *.o insertionsort shellsort mergesort

#clean and then compile
refresh: clean all
