#            makefile for trigTable
#               by  Lorelai Lyons
#                   Sep, 18, 2023
#
#  This is the makefile for my trigTable program.


#  The trigTable target is being used to load the module trigTable.
#    This has the dependencies trigTable.o
trigTable:  trigTable.o
        gcc -o trigTable  trigTable.o -lm

#   trigTable.o is the object file from the compilation of trigTable.c
#   If trigTable.c has changed, or if trigTable.o does not exist - then this will be created.
trigTable.o:  trigTable.c
        gcc -c trigTable.c

#   Delete the all of the object files. This is done with the command "make clean".
clean:
        rm *.o
