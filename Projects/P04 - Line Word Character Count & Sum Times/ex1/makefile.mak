#            makefile for sumTimes2
#               by  Lorelai Lyons
#                   Sep, 22, 2023
#
#  This is my make file for the sumTimes2 program.
#  It will instruct the computer on how to compile the program.


#  The sumTimes2 target is being used to load the module sumTimes2.
#    This has the dependency sumTimes2.o
sumTimes2:  sumTimes2.o
        gcc -o sumTimes2  sumTimes2.o

#   sumTimes2.o is the object file from the compilation of sumTimes2.c
#   If sumTimes2.c has changed, or if sumTimes2.o does not exist - then this will be created.
sumTimes2.o:  sumTimes2.c
        gcc -c sumTimes2.c

#   Delete the all of the object files. This is done with the command "make clean".
clean:
        rm *.o