/*                   grades programming assignment
 *                         Lorelai Lyons
 *                            October 21, 2023
 *
 *
 *  Program Assignment: p06
 *  Due Date:  October 28, 2023
 *
 *  This program displays the letter grades of students. It takes the average
 *  grade for each student, and weighs those averages against the percentage value
 *  placed on each category. After determining the students final grade with the
 *  grade() function, we use the gradePrint() function to send the final letter
 *  grade to output.
 *
 */

#include <stdio.h>              //Standard pre-processing directive.

#include "grades.h"             //Included in order to call gradePrint() and grades()

int main(void)
{
    int  i = 0;                 //Used to increment through grades and student names.
    int  grades[9][5] = {{95, 93, 95, 99, 94},//This is the collection of student averages.
                         {95, 86, 88, 87, 89},
                         {70, 50, 65, 50, 57},
                         {85, 78, 81, 82, 88},
                         {85, 72, 75, 68, 75},
                         {80, 85, 80, 88, 93},
                         {75, 65, 65, 52, 55},
                         {95, 85, 95, 88, 92},
                         {95, 85, 75, 81, 75}};

    char *names[] = { "Adams, Tom", "Curry, Jane", "Franklin, John",//This is the collection of
                      "George, Pat", "Keene, Mary", "Kraft, Martin",//all the student names.
                      "Martin, James", "Oakley, Anne", "Smith, Luke" };

    printf("\n");      //Formatting

    for(i ; i < 9; i++)//Iterates through for each student in the class.
    {
        printf("%-15s ", names[i]);//Prints each student name.
        gradePrint(grade(grades[i][0],grades[i][1],grades[i][2],grades[i][3],grades[i][4], 5, 20, 35, 25));
    }   /*Above: 'gradePrint()' uses 'grades()' in order to print the correct letter grade and corresponding message to output*/

    printf("\n");      //Formatting

    return 0;                          //End of the program.
}
