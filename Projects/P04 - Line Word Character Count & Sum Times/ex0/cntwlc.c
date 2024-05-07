/*                    cntwlc programming assignment
 *                         Lorelai Lyons
 *                            September 30, 2023
 *
 *
 *  Program Assignment: p04
 *  Due Date:  October 14, 2023
 *
 *  This program will count the number of lines, words, and characters from the standard
 *  the input. I will redirect the input of the program to read from an already existing file.
 *  The program will end after displaying the resulting output to the user.
 *
 */

#include <stdio.h>                     //Standard pre-processing directives
#include <stdlib.h>

int main(void)
{
    int    counter, i, c, sumArray[6]; //Declaring Variables

    for(i = 0; i <= 5; i++)            //Assign the value of 0 to each element of the return array.
        sumArray[i] = 0;

    printf("\nWelcome to the CIS158 version of word count.\n\n");  //Introduction to the program

    printf("This program will produce statistics about the text entered from standard\n");
    printf("in.\n");

    printf("\nPlease enter your text now. When finished enter a control D to end.\n\n"); //Prompting user input.

    while ((c = (getc(stdin))) != EOF)
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

    printf("\nThank you for using cntwlc. Bye!\n\n");//Goodbye message.

    return 0;                                   //End of the program.
}
				
