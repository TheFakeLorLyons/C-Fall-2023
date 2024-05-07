/*                    cntwlcFunc
 *                        Lorelai Lyons
 *                            September 30, 2023
 *
 *
 *  Program Assignment: p08
 *  Due Date:  November 18, 2023
 *
 *  This program will contain the cntwlc function, that will be called in the file cntwlc1.c.
 *  The function cntwlc will take two arguments: a file pointer, and a string pointer.
 *  From the entered file, the program will count the number of lines, words, and characters
 *  that exist in the file. If no file is entered, it will receive input via getc() from the
 *  standard input. The function will return to main after displaying the output to the user.
 *
 */

#include <stdio.h>                     //Standard pre-processing directives
#include <stdlib.h>

#include "cntwlcFunc.h"

int cntwlc(FILE *ifp, char *input)
{
    int    counter, i, c, sumArray[6]; //Declaring Variables

    /*I should be able to delete these two lines later by intializing sumArray to zero but I will do that momentarily*/
    for(i = 0; i <= 5; i++)            //Assign the value of 0 to each element of the return array.
        sumArray[i] = 0;

    while ((c = (getc(ifp))) != EOF)
    {
        if(c == '\n')                    //If the character is a new line.
           sumArray[0]++;
        else if(c == ' ')                //If the character is a space separating words.
            sumArray[1]++;
        if((c >= '!') || (c <= 126))     //If the character is a character generally.
        {
            sumArray[2]++;

            if(((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z'))) //If the character is alphabetic.
                sumArray[3]++;
            else if((c >= '0') && (c <= '9'))  //If the character is a digit.
                sumArray[4]++;
            else if(((c >= '!') && (c <= '.')) || ((c >= ':') && (c <= '@')) || ((c >= '[') && (c <= '`')) || ((c >= '{') && c <= '~'))
                sumArray[5]++;                 //If the character is a special character.
        }
    }

    printf("\n\n---   Text Statistics:    ---  \n\n");    //Heading for the returned values.

    printf("Lines              %4d \n", sumArray[0]);  //Returns the count of lines.
    printf("Words              %4d \n", sumArray[1] + sumArray[0]);  //Returns the count of words.
    printf("Characters         %4d \n", sumArray[2]);  //Returns the count of characters.
    printf("Alphabetic         %4d \n", sumArray[3]);  //Returns the count of alaphabetic characters.
    printf("Digits             %4d \n", sumArray[4]);  //Returns the count of digits.
    printf("Special            %4d \n", sumArray[5]);  //Returns the count of special characters.

    return 0;                                   //End of the program.
}
