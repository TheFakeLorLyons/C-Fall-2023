/*                      MyRand Programming Asignment
 *                         by Lorelai Lyons
 *                            September 8, 2023
 *
 *
 *  Program Assignment: p02, ex0
 *  Due Date:  September 29, 2023
 *
 *  This program will produce a table of a unique sequence of random integers.
 *  The user will be able to enter an integer in order to determine how many rows
 *  are included in the table of randomly generated numbers. The program will begin
 *  with an introduction and end with a thank you message.
 *
 */

#include <stdio.h>                              //Standard pre-processing directives
#include <stdlib.h>
#include <math.h>                               //For absolute value for input
#include <time.h>                               //For the time function for seeding random generator

#define THANK_YOU "\n\nThank you for using myrand. Bye!\n\n"

int main(void)
{
   int    randNum, numRows, i, x, randArray[5]; //declaring all the variables
   void   buildArray(int[], int);

   srand(time(NULL));                           //This allows for me to call a random number,
                                                   //based on the seed of the current time.
   printf("\nWelcome to myrand.\n");            //Introduction to the program

   printf("\nThis program will produce a five column table of random numbers.\n");

   printf("\nPlease enter the number of rows you would like: ");//getting the first input
   scanf("%d", &numRows);

   if(numRows < 0)                              //If a negative number is entered, take the
   {                                            //absolute value.
      numRows = abs(numRows);
   }

   for(i = 0; i < numRows; i++)                 //We will iterate random numbers until the correct
   {                                            //number of rows is generated.
      for(x = 0; x <= 5; x++)
      {
         buildArray(randArray, 5);
      }

      printf("\n   %10d\t   %10d\t   %10d\t   %10d\t   %10d\t", randArray[0], randArray[1], randArray[2], randArray[3], randArray[4]);
   }

   printf(THANK_YOU);                          //goodbye message

   return 0;
}

void buildArray(int input[], int n)            //This fills my array with random numbers
{
   int   a;

   for(a = 0; a < n; a++)                      //passing in 5 numbers each time
   {
      input[a] = rand();                       //uses a random number that is seeded by the current time.
   }
}

