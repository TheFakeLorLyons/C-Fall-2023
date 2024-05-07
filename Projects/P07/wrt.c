/*                  wrt.c
 *                      entered by Lorelai Lyons
 *                      October 24.2023
 *
 *   Program Assignment: A07
 *   Due Date: October 27, 2014

 *   From A Book on C, Page 269
 *
 *   Part of 6.9, An Example of Merge and Merge Sort - Pages 263-269
 *
 */

#include "mergesort.h"  //Including our header file with the function definitions.

void wrt(int key[], int sz)//Function header - takes an array and an integer and returns nothing.
{
    int i;              //Declaring the local variable 'i' as an incrementer.

    for(i = 0; i < sz; ++i)//Iterates through the array up to the given size (sz).
       printf("%4d%s", key[i], ((i < sz -1) ? "" : "\n"));//Prints elements to standard output.
}
