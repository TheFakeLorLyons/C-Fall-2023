#            makefile for primeNum
#               by  Lorelai Lyons
#                   Oct 10, 2023
#
#  This is my make file for the primeNum program.
#  It will instruct the computer on how to compile the program.


#  The primeNum target is being used to load the module primeNum.
#    This has the dependency primeNum.o
primeNum:  primeNum.o
        gcc -o primeNum  primeNum.o

#   primeNum.o is the object file from the compilation of primeNum.c
#   If primeNum.c has changed, or if primeNum.o does not exist - then this will be created.
primeNum.o:  primeNum.c
        gcc -c primeNum.c

#   Delete the all of the object files. This is done with the command "make clean".
clean:
        rm *.o
