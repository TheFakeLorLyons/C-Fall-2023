/*                       grades.h
 *                          entered by Lorelai Lyons
 *                            October 24.2023
 *
 *   Program Assignment: p06
 *   Due Date: October 28, 2014
 *
 *
 *   This header file will include all of the necessary function definitions
 *   for the functions that will be called throughout the 'grades' program.
 *
 */
/*The grade functions calculates the percentage grade based off of the student averages.*/
int grade(int attendance, int  assignments, int programs, int quizzes, int finalExam,
          int per_Attend, int per_Assign, int per_Prog, int per_Quiz);

int gradePrint(int n);
/*The gradePrint function prints the letter grades to standard output.*/
