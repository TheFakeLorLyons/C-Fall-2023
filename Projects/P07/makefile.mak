#            makefile for mergeSort
#               by
#                 November 4, 2023
#
#  This is my second make file for the mergesort program.
#  It will instruct the computer on how to compile the program.


#  The mergesort target is being used to load the module mersort.
#    This has the dependency mergesort.o
sort158a:  sort158a.o mergesort.o merge.o wrt.o
        gcc sort158a.o merge.o mergesort.o wrt.o -o sort158a

#   merge.o is the object file from the compilation of merge.c
#   If merge.c has changed, or if merge.o does not exist - then this will be created.
merge.o:  merge.c mergesort.h
        gcc -c merge.c

#   mergesort.o is the object file from the compilation of mergesort.c
#   #   If mergesort.c has changed, or if mergesort.o does not exist - then this will be created.
mergesort.o:  mergesort.c mergesort.h
        gcc -c mergesort.c

#   wrt.o is the object file from the compilation of wrt.c
#   If wrt.c has changed, or if wrt.o does not exist - then this will be created.
wrt.o:  wrt.c mergesort.h
        gcc -c wrt.c

#   Delete the all of the object files. This is done with the command "make clean".
clean:
        rm *.o
