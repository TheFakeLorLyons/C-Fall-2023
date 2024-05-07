/*                   primeNum  programming assignment
 *                         Lorelai Lyons
 *                            October 10, 2023
 *
 *
 *  Program Assignment: p05
 *  Due Date:  October 20, 2023
 *
 *  This program will take an two integers - 'begin' and 'end' from a user,
 *  and determine and produce the list of prime numbers that exist between the two
 *  values. I use a for loop to iterate through the numbers, and the function
 *  'primeNum' to determine whether an individual number is prime or not.
 *
 */

#include <stdio.h>                              //Standard pre-processing directive.

int primeNum(int checkInput);                   //Function declaration for the primeNum function.

int main(void)
{                                               //Declaring variables & function prototypes.
    int   begin, end;

    printf("\nWelcome to primeNum.\n\n");       //Introduction to the program.

    printf("This program will display the prime integers that are in the range\n");

    printf("between the two integers you enter.\n");

    printf("\nPlease enter the beginning integer: ");    //Prompting user input.
    scanf("%d", &begin);

    printf("\nPlease enter the ending integer: ");       //Prompting user input.
    scanf("%d", &end);

    printf("\n");                      //Formatting.

    for(begin; begin <= end; begin++)  //Iterating through the list of all whole integers between 'begin',
    {                                          //and 'end'.
         primeNum(begin);
    }

    printf("\nThank you for using primeNum. Bye!\n\n"); //Goodbye message.

    return 0;                          //End of the program.
}

int primeNum(int checkInput)           //primeNum takes the one integer and determines if it is a prime number.
{                                        //by counting the number of factors the integer has. More than 1 factor = prime.
    int incrementer = 1, ans = 1, factors = 0;//Local variable declaration.

    for(incrementer; incrementer < checkInput; incrementer++)//This loop counts from 1 up to the number input number.
    {
         if((checkInput % incrementer) == 0)//If the number is evenly distributable into a lower number, the lower
         {                                    //number is considered a 'factor' of that number.
             ++factors;                     //Adding 1 to the count of factors the number has.
         }
         if(factors > 1)                    //If the factor count is greater than one, we can stop iterating and return 0.
             return 0;
    }
    if(ans == 1)                            //If there is only 1 factor (the number 1 itself), the number is prime and we
         printf("%d \n", checkInput);         //print it to output.

    return 0;                               //Since we printed the number if it got this far, we can return to the main function
}      
