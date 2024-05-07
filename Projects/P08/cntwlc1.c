/*                    cntwlc programming assignment
 *                         Lorelai Lyons
 *                            November 18, 2023
 *
 *
 *  Program Assignment: p08
 *  Due Date:  November 18, 2023
 *
 *  This second version of my cntwlc project will have the main function call the cntwlc
 *  function in order to read the number of words, lines, and characters that are read from
 *  the standard input. The program will end after displaying the resulting output to the user.
 *
 */

#include <stdio.h>                     //Standard pre-processing directives
#include <stdlib.h>

#include "cntwlcFunc.h"

int main(int argv, char *argc[])
{
    int    i = 0, c;//Declaring Variables
    FILE   *ifp, *ofp; //Declaring Variables

    for(i; i < argv; i++)
    {
       /*Here is for NO INPUT*/
       if(argv < 2)
       {
          ofp = fopen("tmp","w+");  //Open a temporary file.
          if (ofp == NULL)          //Checking to make sure it was created correctly.
          {
             perror("Error opening temporary file");
             return 1;
          }

          printf("\nWelcome to cntwlc1 the CIS158 version of word count.\n");//Program introduction

          printf("The program will read stdin (standard input) until it encounters an \nend of file marker (The user enters a Ctrl D)");

          printf("This program will produce statistics about the test entered from standard in\n");

          printf("Please enter your test now. When finished enter a control D to end.\n");

          while((c = getc(stdin)) != EOF)//Takes standard input until ctrl+d
          {
             putc(c, ofp);               //Places the input into an output file
             if(c == '\n')               //If it is a newline it will be a newline character.
               putc('\n', ofp);
          }

          fclose(ofp);                   //Closing the file from being written
          ofp = fopen("tmp", "r");       //Opening the new file to pass to cntwlc

          cntwlc(ofp, argc[i]);          //Using the new file in the cntwlc function.

          fclose(ofp);                   //Closing the file stream.

          break;
       }

       /*Here is ONE OR MORE FILES*/
       else if(i > 0)
       {
          ifp = fopen(argc[i], "r");     //This reads the input files, one at a time.

          /*Here is for errors*/
          if(ifp == NULL)//If the file cannot be found, send this error.
          {
             printf("\n      ----  ERROR  ----     \n");
             printf("The file %s can not be found\n", argc[i]);
             break;
          }

          cntwlc(ifp, argc[i]);          //Calling the function with the input files.

          fclose(ifp);                   //Closing the file stream.
       }
    }

    printf("\nThank you for using ctnwlc1. Bye!\n\n");

    return 0;                                   //End of the program.
}
