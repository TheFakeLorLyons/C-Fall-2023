/*                      NameAge Programming Project
 *                         by Lorelai Lyons
 *                            September 6, 2023
 *
 *
 *  Program Assignment: p01, ex1
 *  Due Date:  September 23, 2023
 *
 *  This program will ask the user for their name and age and produce
 *  a message indicating how old they will be next year. After this,
 *  the program will display a corresponding message about their retirement
 *  based on how old they are. The program ends with a thank you message.
 *
 */

#include <stdio.h>                    //standard pre-processing directives
#include <stdlib.h>

int main(void)
{
   int    difference, age, i;         //declaring integer variables
   char   c, name[100];               //declaring character variables

   printf("\nWelcome to nameage\n");  //program introduction

   printf("\nPlease enter name: \n");

   for(i = 0; (c = getchar()) != '\n'; ++i)//obtaining user's name
   {
      if(i >= 100)                    //if it is greater than maxsize, then just give up
      {                               //(this program would just cut the name off and go)
         break;
      }
      name[i] = c;                    //assigning each character to it's spot in the array 'name'
   }
   name[i] = '\0';                    //the last character in the string should be '\0'

   printf("Please enter your age: \n");//asking for and obtaining the user's age
   scanf("%d", &age);
   difference = 67 - age;             //if the age is less than 67, obtains the difference to print out later

   printf("\nHi, %s, you are %d years old... \n" , name, age);//repeating back input
   printf("Next year you will be %d years old... \n", age+1);//increament year by one like it says in instructions
     
   if(age == 67)                      //check if the age is exactly the retirement age first
   {
      printf("Aw nice, you should be able to retire now :)\n");//if so we can just celebrate and leave
   }
   else if(age > 67)                  //If they are past retirement age then that is unfortunate and they will see this
   {
      printf("You should be retired already!\n");//rubbing a bit of salt into the wound with this comment, as they probably know lol
   }
   else                               //if they aren't 67, or older than that, we will figure out how much longer till retirement
   {
       printf("you have %d years left till retirement...\n", difference);//Tells them the difference
   }

   printf("\nThank you for using nameage, bye!\n\n");//goodbye message

   return 0;
}
         