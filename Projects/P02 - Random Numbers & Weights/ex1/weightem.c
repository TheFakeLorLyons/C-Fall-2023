/*                      Weightem
 *                         by Lorelai Lyons
 *                             September 7, 2023
 *
 *
 *  Program Assignment: p02, ex01
 *  Due Date:  September, 29 2023
 *
 *  This program will be a conversion tool that allows users
 *  to convert standard English weights to standard Metric weights,
 *  and vice versa.
 *
 */

#include <stdio.h>                                //Standard Pre-processing directives.
#include <stdlib.h>
#include <ctype.h>                                //Used for the 'tolower' function for character input.

#define THANK_YOU "\nThank you for using weightem. Bye!\n"//Thank you message to be used throughout.

int main(void)
{
   char    choice;                                //Input character to select the unit to convert.
   int     converter(float, int, int);            //Function prototype for my conversion function.
   float   input;                                 //The weight input for the converter function.

   printf("\nWelcome to weightem. The program will convert weights from English to Metric or Metric to\n");
   printf("English. Indicate which conversion from the selection below.\n");//Introduction

   printf("\n1. Pounds to Kilos\n");              //Displays the selection of unit conversions to the user.
   printf("2. Kilos to Pounds\n");
   printf("3. Ounces to Grams\n");
   printf("4. Grams to Ounces\n");
   printf("5. Exit - Do Nothing (default)\n");    //If nothing is selected, exit.

   printf("\nYour Choice: ");                     //Prompting user input.
   scanf("%c", &choice);                          //User input.

   switch(tolower(choice))                        //Main switch statement based on the desired conversion.
   {
      case '1':                                   //All cases take either a number or a lowercase character.
      case 'p':
         printf("\nEnter the number of pounds you would like converted: ");//Solicit weight input
         scanf("%f", &input);                     //User input
         converter(input, 0, 1);                  //Calling my helper function "coverter".
         break;
      case '2':                                   //Each case is the same aside from which unit is being converted.
      case 'k':
         printf("\nEnter the number of kilograms you would like converted: ");
         scanf("%f", &input);
         converter(input, 1, 1);
         break;
      case '3':                                   // "  "
      case 'o':
         printf("\nEnter the number of ounces you would like converted: ");
         scanf("%f", &input);
         converter(input, 1, 0);
         break;
      case '4':                                   // "  "
      case 'g':
         printf("\nEnter the number of grams you would like converted: ");
         scanf("%f", &input);
         converter(input, 0, 0);
         break;
      default:                                    //If the entered character matches nothing, exit the program.
         printf(THANK_YOU);
         exit(1);
   }

   return 0;
}

int converter(float weight, int metricOrEnglish, int gramsOrKilos)//Conversion helper function
{
   float convertedOutput;                //Final output - the calculated, converted, weight.

   if(metricOrEnglish == 1)              //Converting Metric to English
   {
      if(gramsOrKilos == 1)              //Does it involve Grams or Kilograms?
      {
         convertedOutput = (weight / .4536); //This represents Kilograms to Pounds
         printf("\nAnswer: %.4f kilograms is %.4f pounds\n", weight, convertedOutput);
      }
      else
      {
         convertedOutput = (weight * 28.35); //This represents Grams to Ounces
         printf("\nAnswer: %.2f ounces is %.2f grams\n", weight, convertedOutput);
      }
   }
   else
   {
      if(gramsOrKilos == 1)              //Does it involve Grams or Kilograms?
      {
         convertedOutput = (weight * .4536); //This represents Pounds to Kilograms
         printf("\nAnswer: %.4f pounds is %.4f kilograms\n", weight, convertedOutput);
      }
      else
      {
         convertedOutput = (weight / 28.35);  //This represents Ounces to Grams
         printf("\nAnswer: %.2f grams is %.2f ounces\n", weight, convertedOutput);
      }
   }

   printf(THANK_YOU);                    //The end of the program!

   return 0;
}