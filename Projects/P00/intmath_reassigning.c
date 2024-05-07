/*                      Int Math
 *                         by Lorelai Lyons
 *                            September 5, 2023
 *
 *
 *  Program Assignment: p00
 *  Due Date:  Sep 16, 2023
 *
 *  This program will display a brief description of what it does,
 *  and then take user input, in the form of 2 integeers - one at time,
 *  and assign those values to two separate variables. The program will
 *  then print out the sum, difference, product, quotient, and modulus
 *  of the two entered integers.
 */

#include <stdio.h>                                 //preprocessing directives
#include <stdlib.h>

int main(void)
{
   int     uinput1, uinput2, result;

   printf("\nWelcome to the intmath program.\n");

   printf("\nIn this program, we will take two separately entered integers, \n");
   printf("and perform 5 mathematical operations on them: addition, subtraction, \n");
   printf("multiplication, division, and modulus; and return the solutions to the user.\n");

   printf("\nPlease Enter the first number: ");
   scanf("%d", &uinput1);

   printf("Please Enter the second number: ");
   scanf("%d", &uinput2);

   result = uinput1+uinput2;
   printf("\nThe sum of these two numbers is: ");
   printf("%d\n", result);

   result = uinput1-uinput2;
   printf("The difference of these two numbers is: ");
   printf("%d\n", result);

   result = uinput1*uinput2;
   printf("The product of these two numbers is: ");
   printf("%d\n", result);

   result = uinput1/uinput2;
   printf("The quotient of these two numbers is: ");
   printf("%d\n", result);

   result = uinput1%uinput2;
   printf("The sum of these two numbers is: ");
   printf("%d\n", result);

   printf("\nThank you for using intmath. Bye!");

   return 0;
}


