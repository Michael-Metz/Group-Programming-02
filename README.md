# Group-Programming-02
Insertion Sort, Shell Sort, Merge Sort w/ c++

We are using makefile to compile our programs

The assignment has three deliverable programs

1. insertionsort
2. shellsort
3. mergesort

typing `make all` will compile all of these down to three deliverable programs

to run the programs type the following

```
insertionsort infile outfile
shellsort infile outfile
mergesort infile outfile
```
where `infile` is the path to the input file containing the numbers you want to sort
where `outfile` is the path to the file you want to save the sorted numbers

#### Here are some other targets in the makefile

* `make clean` removes all the deliverables and object files
* `make refresh` cleans and then compiles everything again
* `make insertionsort` creates a deliverable for just insertionsort
* `make shellsort` creates a deliverable for just shellsort
* `make mergesort` creates a deliverable for just mergesort
