#            makefile for cntwlc1
#               by
#                   November 18, 2023
#
#  This is my make file for the cntwlc1 program.
#  It will instruct the computer on how to compile the program.


#  The cntwlc1 target is being used to load the module cntwlc1.
#    This has the dependency cntwlc1.o
cntwlc1:  cntwlc1.o cntwlcFunc.o
        gcc cntwlc1.o cntwlcFunc.o -o cntwlc1

#   cntwlc1.o is the object file from the compilation of cntwlc1.c
#   If cntwlc1.c has changed, or if cntwlc1.o does not exist - then this will be created.
cntwlc1.o:  cntwlc1.c cntwlcFunc.h
        gcc -c cntwlc1.c

#   cntwlcFunc.o is the object file from the compilation of cntwlcFunc.c
#   #   If cntwlcFunc.c has changed, or if cntwlcFunc.o does not exist - then this will be created.
cntwlcFunc.o:  cntwlcFunc.c cntwlcFunc.h
        gcc -c cntwlcFunc.c


#   Delete the all of the object files. This is done with the command "make clean".
clean:
        rm *.o
