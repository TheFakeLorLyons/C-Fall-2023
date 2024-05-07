#            makefile for ip158
#               by
#                   November 27, 2023
#
#  This is my make file for the ip158 program.
#  It will instruct the computer on how to compile the program.


#  The ip158 target is being used to load the module ip158.c.
#    This has the dependency ip158.o
ip158:  ip158.o ipfunc.o bit_print.o
        gcc ip158.o ipfunc.o bit_print.o -o ip158

#   ip158.o is the object file from the compilation of ip158.c
#   #   If ip158.c has changed, or if ip158.o does not exist - then this will be created.
ip158.o:  ip158.c
        gcc -c ip158.c

#   ipfunc.o is the object file from the compilation of ipfunc.c
#   If ipfunc.c has changed, or if ipfunc.o does not exist - then this will be created.
ipfunc.o:  ipfunc.c ipfunc.h
        gcc -c ipfunc.c

#   bit_print.o is the object file from the compilation of bit_print.c
#   #   If bit_print.c has changed, or if bit_print.o does not exist - then this will be created.
bit_print.o:  bit_print.c
        gcc -c bit_print.c

#   Delete the all of the object files. This is done with the command "make clean".
clean:
        rm *.o