#            makefile for myrand
#               by  Lorelai Lyons
#                   Sep, 16, 2023
#
#  This is my first make file for the myrand program.
#  This make file will instruct the computer how to
#  compile the program.


#  The myrand target is being used to load the module myrand.
#    This has the dependency myrand.o
myrand:  myrand.o
        gcc -o myrand  myrand.o

#   myrand.o is the object file from the compilation of myrand.c
#   If myrand.c has changed or myrand.o does not exist - then this will be created.
myrand.o:  myrand.c
        gcc -c myrand.c

#   Delete the all of the object files. This is done with the command "make clean".
clean:
        rm *.o
