/*             Trigonometric Table Programming Asignment
 *                  By Lorelai Lyons
 *                       September 12, 2023
 *
 *
 *   Program Assignment: p03
 *   Due Date:  October 7, 2023
 *
 *   This program will take an integer from a user that will serve
 *   as starting point for a table containing the value of the degrees,
 *   radians, sine, cosine, and tangent of corresponding and iterative
 *   degrees between 0 and 360 degrees.
 *
 */

#include <stdio.h>                      //Standard pre-processing directives
#include <stdlib.h>
#include <math.h>                       //included for radians/sine/cosine/tangent function

int main(void)
{
        int     degrees, end, displayTriTab(int degrees);//declaring all the variables
                                                         //and displayTriTab function prototype
        printf("\nWelcome to trigTable.\n");             //introduction to the program

        printf("\nThis program will print a table of trigonometric values\n");
        printf("  from 0 to 360 degrees to increments selected by the user.\n");

        printf("\nPlease select the number of degrees for the increment: ");
        scanf("%d", &degrees);

        printf("\n");

        displayTriTab(degrees);

        printf("\n\nThank you for using trigTable. Bye!\n\n");//goodbye message

        return 0;
}

int displayTriTab(int degrees)
{
    int   incrementer = 0;
    float i, radians, sine, cosine, tangent;

    printf("        ---      TRIGONOMETRIC TABLE      ---       \n");
    printf("\n Degrees  Radians     sine      cosine     tangent\n");//just formatting for display
    printf(" _______  _______    ______     ______    _________\n\n");

    for(i = 0; incrementer < 360; i++)
    {
         if(incrementer == 90 || incrementer == 270)
         {
              radians = incrementer * (M_PI / 180);
              sine = sinf(radians);
              cosine = cosf(radians);

              printf("\n   %3d\t   %6.4f   %7.4f    %7.4f    infinity", incrementer, radians, sine, cosine);
              incrementer += degrees;
         }

         radians = incrementer * (M_PI / 180);
         sine = sinf(radians);
         cosine = cosf(radians);
         tangent = tanf(radians);

         printf("\n   %3d\t   %6.4f   %7.4f    %7.4f    %8.5f", incrementer, radians, sine, cosine, tangent);
         incrementer += degrees;
     }

     if(incrementer >= 360)
     {
         incrementer = 360;
         radians = incrementer * (M_PI / 180);
         sine = sinf(radians);
         cosine = cosf(radians);
         tangent = tanf(radians);
         printf("\n   %3d\t   %6.4f   %7.4f    %7.4f    %8.5f", incrementer, radians, sine, cosine, tangent);

     }

    return 0;
}
