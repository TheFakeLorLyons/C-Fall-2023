#            makefile for weightem
#               by  Lorelai Lyons
#                   Sep, 16, 2023
#
#  This is my second make file overall, this time for the weightem program.


#  The weightem target is being used to load the module weightem.
#    This has the dependency weightem.o
weightem:  weightem.o
        gcc -o weightem  weightem.o

#   weightem.o is the object file from the compilation of weightem.c
#   If weightem.c has changed, or if weightem.o does not exist - then this will be created.
weightem.o:  weightem.c
        gcc -c weightem.c

#   Delete the all of the object files. This is done with the command "make clean".
clean:
        rm *.o
