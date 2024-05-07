#include <stdio.h>
#include <stdlib.h>       //Standard pre processing directives.

#include "bit_print.c"    //I am using this for the bit print function.

int main(void)
{
   int testIntEmployeeID = 'A'; //Local variable declaration.

   typedef enum boolean {false, true} boolean; //Bool type

   enum day {Sun, Mon, Tue, Wed, Thu, Fri, Sat} days;//New days type.

   enum day thisDay = Fri;

   typedef float scrub;       //Nonsense

   typedef scrub scrubAStomp[];//A lot of nonsense

   typedef union subjectOrTime{
      char *subject;
      int time;
      scrub scram;
   }trial;

   typedef struct{               //My main structure to practice with
      int *obligatory;           //Pointer to the identifier (in a DB)
      char *name;                //Pointer to the name of the noobprogrammer
      boolean bitTest;           //Test of my new boolean
      trial wordUp;
   }n00bProgrammer;              //Declaring a new n00bProgrammer.

   bit_print(testIntEmployeeID); //Prints variable in binary.

   if(thisDay == Fri)            //If my enum works...
      printf("\n1\n");           //Print 1
   else                          //If it doesn't...
      printf("I give up.");      //I will quit programming.

   n00bProgrammer Page;          //Declaring myself. As a n00BproBrmamer

   Page.obligatory = &testIntEmployeeID;  //identifier is the address of the variable I declared.
   Page.name = "Page";           //Declaring my name
   Page.wordUp.subject = "Philosophrizzle";

   printf("\nID: %d \nName: %s \n bitTest: %d", Page.obligatory, Page.name, Page.bitTest);//see if a bool works for bit test %b

   printf("\n %s \n", Page.wordUp);

   return 0;                     //End of the program
}

//prn_struct_details(n00b
