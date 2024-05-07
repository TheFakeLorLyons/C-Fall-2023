/*                    sumTimes2 programming assignment
 *                         Lorelai Lyons
 *                            September 19, 2023
 *
 *
 *  Program Assignment: p04
 *  Due Date:  October 14, 2023
 *
 *  This program will take an integer (daNumba) from a user and produce the sum of
 *  the input number and each number between it and twice its value. The Program will
 *  perform this operation twice - once utilizing for loops, and again using only while loops.
 *
 */

#include <stdio.h>                              //Standard pre-processing directives
#include <stdlib.h>

int main(void)
{                                               //declaring variables & function prototypes
    int    daNumba, sumFor(int daNumba), sumWhile(int daNumba);

    printf("\nWelcome to sumTimes2.\n\n");        //Introduction to the program

    printf("This program will sum the integers between the one you enter and the\n");
    printf("integer that is twice that value.\n");

    printf("\nPlease enter your integer: ");    //Prompting user input
    scanf("%d", &daNumba);

    printf("\n");

    sumFor(daNumba);                            //Calling the sumFor function
    sumWhile(daNumba);                          //Calling the sumWhile function

    printf("\n\nThank you for using sumTimes2. Bye!\n\n");//Goodbye message

    return 0;                                   //End of the program.
}

int sumFor(int daNumba)                //sumFor takes daNumba and adds it with a for loop.
{
        int sum = daNumba, twiceit = daNumba *2, i = sum + 1;//local variable declaration

        for(i; i <= twiceit; i++)      //This loop adds 'i' to 'sum' beginning with 'sum + 1'
              sum += i;                  //until 'i' is equal to 'twiceit'.

        printf("For says the sum is %d \n", sum);//Printing the completed sum.

        return 0;                      //Returning the value of 0 to main since we already
}                                        //printed and do not require a value.

int sumWhile(int daNumba)              //sumWhile takes daNumba and adds it using a while loop.
{
        int sum = daNumba, twiceit = daNumba *2, i = sum + 1;

        while(i <= twiceit)            //This loop adds 'i' to 'sum' beginning with 'sum + 1'
                sum += i, i++;           //printed and do not require a value.

        printf("While says the sum is %d \n", sum);

        return 0;                       //Returning the value of 0 to main since we already
}                                         //printed and do not require a value.
                                     