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
   int     uinput1, uinput2, sum, difference, product, quotient, modulus;//declaring variables

   printf("\nWelcome to the intmath program.\n");  //introduction to the program

   printf("\nIn this program, we will take two separately entered integers, \n");
   printf("and perform 5 mathematical operations on them: addition, subtraction, \n");
   printf("multiplication, division, and modulus; and return the solutions to the user.\n");

   printf("\nPlease Enter the first number: ");    //taking input for the first number
   scanf("%d", &uinput1);

   printf("Please Enter the second number: ");     //taking input for the second number
   scanf("%d", &uinput2);

   sum = uinput1+uinput2;                          //(input1)+(input2)
   printf("\nThe sum of these two numbers is: ");
   printf("%d\n", sum);

   difference = uinput1-uinput2;                   //(1-2)
   printf("The difference of these two numbers is: ");
   printf("%d\n", difference);

   product = uinput1*uinput2;                      //(1*2)
   printf("The product of these two numbers is: ");
   printf("%d\n", product);

   quotient = uinput1/uinput2;                     //(1/2)
   printf("The quotient of these two numbers is: ");
   printf("%d\n", quotient);

   modulus = uinput1%uinput2;                      //(1%2)
   printf("The sum of these two numbers is: ");
   printf("%d\n", modulus);

   printf("\nThank you for using intmath. Bye!");  //goodbye message

   return 0;
}
