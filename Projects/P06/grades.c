/*                   grades.c programming assignment
 *                         Lorelai Lyons
 *                            October 22, 2023
 *
 *
 *  Program Assignment: p06
 *  Due Date:  October 28, 2023
 *
 *  This helper file includes two functions: grade(), and gradePrint(); for use
 *  in the main function in cis158g1.c
 *
 *  grade() takes all the Pt averages and corresponding percent weights for each
 *  grade category, and returns a final grade number between 0 and 100. If the
 *  input is invalid (average over 105 or under 0, or percent over 100, or final
 *  grade over 105 or under 0), then the program will return -1, -2, or -3 respectively.
 *
 *  gradePrint() takes the integer produced by grade() and sends a letter grade
 *  to output, along with a message that accompanies the letter grade.
 *
 */

#include <stdio.h>                 //Standard pre-processing directive.
#include <stdlib.h>
#include "grades.h"
                                   /*Takes all 9 input variables*/
int grade(int attendance, int assignments, int programs, int quizzes, int finalExam,
              int per_attend, int per_assign, int per_programs, int per_quizzes)
{
    double fGrade, a1, a2, e, q, finalWeight; //Declaring local variables.

    if(((attendance > 100 || assignments > 100|| programs > 100 || quizzes > 100) ||
        (attendance < 0 || assignments < 0 || programs < 0 || quizzes < 0)))
        return -1; //Returns -1 if the averages are invalid values.

    if(((per_attend > 100 || per_assign > 100 || per_programs > 100 || per_quizzes > 100)))
        return -2; //Returns -2 if the percentages are invalid values.

    a1 = (attendance * (per_attend * .01));  //Students weighed attendence.
    a2 = (assignments * (per_assign * .01)); //Students weighed assignments.
    e  = (programs * (per_programs * .01));        //Students weighed programs.
    q  = (quizzes * (per_quizzes * .01));    //Students weighed quizzes.

    fGrade = a1 + a2 + e + q + (finalExam * .15);//Final grade takes all weighed grades and adds weighed final exam.

    if(fGrade > 100 || fGrade < 0)
        return -3; //Returns -3 if the final grade is an invalid value.

    return fGrade; //Returns the final grade to the calling function.
}

int gradePrint(int finalGrade)           //gradePrint takes the one integer.
{
    char grades[5] = { 'A', 'B', 'C', 'D', 'F' }; //Declaring the array of grade values.

    if(finalGrade > 105 || finalGrade < 0) //This will trigger if input is too high or low.
    {
        printf("\n%d is not a valid grade\n", finalGrade);//Error message for output.
        exit(1);                            //Exits program.
    }

/*if else statements will take the final grade and produce the correct output*/
    if(finalGrade >= 97)                                   //A+
        printf("Grade %c+  %s\n:", grades[0], "Excellent");
    else if(finalGrade >= 93)                              //A
        printf("Grade %c   %s\n", grades[0], "Excellent");
    else if(finalGrade >= 90)                              //A-
        printf("Grade %c-  %s\n", grades[0], "Excellent");
    else if(finalGrade >= 87)                              //B+
        printf("Grade %c+  %s\n", grades[1], "Good");
    else if(finalGrade >= 83)                              //B
        printf("Grade %c   %s\n", grades[1], "Good");
    else if(finalGrade >= 80)                              //B-
        printf("Grade %c-  %s\n", grades[1], "Good");
    else if(finalGrade >= 77)                              //C+
        printf("Grade %c+  %s\n", grades[2], "Fair");
    else if(finalGrade >= 73)                              //C
        printf("Grade %c   %s\n", grades[2], "Fair");
    else if(finalGrade >= 70)                              //C-
        printf("Grade %c-  %s\n", grades[2], "Fair");
    else if(finalGrade >= 67)                              //D+
        printf("Grade %c+  %s\n", grades[3], "Poor");
    else if(finalGrade >= 63)                              //D
        printf("Grade %c   %s\n", grades[3], "Poor");
    else if(finalGrade >= 60)                              //D-
        printf("Grade %c-  %s\n", grades[3], "Poor");
    else if(finalGrade < 60)                               //F
        printf("Grade %c   %s\n", grades[4], "Failing Grade");

    return 0; //Since we printed the number if it got this far, we can return to the main function
}             //returning 0.

