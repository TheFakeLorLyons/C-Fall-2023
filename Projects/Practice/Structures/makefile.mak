#            makefile for structs1
#               by Page Rivers
#                 November 13, 2023
#
#  This is my make file for the structs1 program.
#  It will instruct the computer on how to compile the program.


#  The structs1.c target is being used to load the module main.
#    This has the dependency structs1.o
structs1:  structs1.o
        gcc structs1.o -o structs

#   bit_main.o is the object file from the compilation of bit_main.c
#   If bit_main.c has changed, or if bit_main.o does not exist - then this will be created.
structs1.o:  structs1.c bit_print.c
        gcc -c structs1.c bit_print.c

#   lilithst.o is the object file from the compilation of lilithst.c
#   #   If lilithst.c has changed, or if bit_main.o does not exist - then this will be created.
structs1.o:  structs1.c lilithst.c
        gcc -c structs1.c lilithst.c

#   Delete the all of the object files. This is done with the command "make clean".
clean:
        rm *.o