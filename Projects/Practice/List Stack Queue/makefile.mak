#            makefile for lists
#               by Page Rivers
#                 November 23, 2023
#
#  This is my make file for the lists program.
#  It will instruct the computer on how to compile the program.


#  The prn_list.c target is being used to load the module main.
#    This has the dependency prn_list.o
list:  prn_list.o iter_list.o list_fun.o recur_list.o stack.o queue.o
        gcc prn_list.o iter_list.o list_fun.o recur_list.o stack.o queue.o -o list

#   prn_list.o is the object file from the compilation of prn_list.c
#   If prn_list.c has changed, or if list.o does not exist - then this will be created.
prn_list.o:  prn_list.c list.h
        gcc -c prn_list.c list.h

#   iter_list.o is the object file from the compilation of iter_list.c
#   If iter_list.c has changed, or if list.o does not exist - then this will be created.
iter_list.o:  iter_list.c list.h
        gcc -c iter_list.c list.h

#   list_fun.o is the object file from the compilation of list_fun.c
#   If list_fun.c has changed, or if list.o does not exist - then this will be created.
list_fun.o:  list_fun.c list.h
        gcc -c list_fun.c list.h

#   recur_list.o is the object file from the compilation of recur_list.c
#   If recur_list.c has changed, or if list.o does not exist - then this will be created.
recur_list.o:  recur_list.c list.h
        gcc -c recur_list.c list.h

#   stack.o is the object file from the compilation of stack.c
#   If stack.c has changed, or if stack.o does not exist - then this will be created.
stack.o:  stack.c stack.h
        gcc -c stack.c stack.h

#   queue.o is the object file from the compilation of queue.c
#   If queue.c has changed, or if queue.o does not exist - then this will be created.
queue.o:  queue.c queue.h
        gcc -c queue.c queue.h
		
#Delete the all of the object files. This is done with the command "make clean".
clean:
        rm *.o