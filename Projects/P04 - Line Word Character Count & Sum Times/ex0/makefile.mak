#            makefile for cntwlc
#               by  Lorelai Lyons
#                   Sep, 22, 2023
#
#  This is my make file for the cntwlc program.
#  It will instruct the computer on how to compile the program.


#  The cntwlc target is being used to load the module cntwlc.
#    This has the dependency cntwlc.o
cntwlc:  cntwlc.o
        gcc -o cntwlc  cntwlc.o

#   cntwlc.o is the object file from the compilation of cntwlc.c
#   If cntwlc.c has changed, or if cntwlc.o does not exist - then this will be created.
cntwlc.o:  cntwlc.c
        gcc -c cntwlc.c

#   Delete the all of the object files. This is done with the command "make clean".
clean:
        rm *.o
