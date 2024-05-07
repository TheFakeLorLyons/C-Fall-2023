/*                      Powers Programming Asignment
 *                         by Lorelai Lyons
 *                            September 6, 2023
 *
 *
 *  Program Assignment: p01, ex0
 *  Due Date:  September 23, 2023
 *
 *  This program will take an input of two integers from a user and display
 *  a table to the user that indicates the powers of each number in the
 *  series, up to the 5th power for each.
 *
 */

#include <stdio.h>                              //Standard pre-processing directives
#include <stdlib.h>
#include <math.h>                               //included for 'power' function

int main(void)
{
   int    start, end, i, powers[5];             //declaring all the variables

   printf("\nWelcome to the Powers program\n"); //introduction to the program

   printf("\nThis program will take two separate integers, and display \n");
   printf("All of the powers, up to the fifth power - for each number between\n");
   printf("the two integers provided.\n");

   printf("\nPlease enter the beginning integer: ");//getting the first input
   scanf("%d", &start);

   printf("\nYou entered %d, please enter the ending integer: ", start);//getting the second input
   scanf("%d", &end);

   if(end < start)                              //switches inputs if the second number is greater
   {
      int tempnum = end;
      end = start;
      start = end;
   }

   printf("\nInteger\tSquare\t3rd Power  4th Power  5th Power\n");//just formatting for display
   printf("_______\t______\t_________  _________  _________\n");


   for(i = start; i <= end; i++)                //This array calculats and stores all the operations up to the fifth
   {                                            //power for each iteration between the starting and ending numbers
      powers[0] = (i);
      powers[1] = (pow(i, 2));
      powers[2] = (pow(i, 3));
      powers[3] = (pow(i, 4));
      powers[4] = (pow(i, 5));
                                                //The line below this comment displays each power for each iteration
      printf("\n    %3d   %4d    %6d   %8d  %9d", powers[0], powers[1], powers[2], powers[3], powers[4], powers[5]);
   }

   printf("\n\nThank you for using the 'Powers' program. Bye!\n\n");//goodbye message

   return 0;
}