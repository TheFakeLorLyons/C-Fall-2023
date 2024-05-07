#            makefile for grades
#               by Lorelai Lyons
#                   Oct 28, 2023
#
#  This is my make file for the grades program.
#  It will instruct the computer on how to compile the program.


#  The grades target is being used to load the module mersort.
#    This has the dependency mergesort.o
cis158g1:  cis158g1.o grades.o
        gcc grades.o cis158g1.o -o cis158g1

#   cis158g1.o is the object file from the compilation of cis158g1.c
#   #   If cis158g1.c has changed, or if cis158g1.o does not exist - then this will be created.
cis158g1.o:  cis158g1.c grades.h
        gcc -c cis158g1.c -lm

#   grades.o is the object file from the compilation of grades.c
#   If grades.c has changed, or if grades.o does not exist - then this will be created.
grades.o:  grades.c grades.h
        gcc -c grades.c -lm

#   Delete the all of the object files. This is done with the command "make clean".
clean:
        rm *.o
