/*                 merge.c
 *                      entered by Lorelai Lyons
 *                      October 24.2023
 *
 *   Program Assignment: A07
 *   Due Date: October 27, 2014

 *   From A Book on C, Page 264
 *
 *   Part of 6.9, An Example of Merge and Merge Sort - Pages 263-269
 *
 */

/* Merge a[] of size m and b[] of size n into c[].*/

#include "mergesort.h"

/*a[] is our input, b[] is the comparison, c[] is the array to be produced
 * m is the total number of integers in the input array, n and m are the sizes
 * of the arrays a and b respectively.*/
void merge(int a[], int b[], int c[], int m, int n)//Function header.
{
    int i = 0, j = 0, k = 0; //Declaring local variables

    while( i < m && j < n)  //Iterating through the input arrays.
        if(a[i] < b[j])     //Comparing the first integer group.
            c[k++] = a[i++];//If a[i] is lower, then we assign it to c[k++]
        else
            c[k++] = b[j++];//otherwise c[k++] is equal to the other integer.
    while(i < m)            /* pick up any remainder */
        c[k++] = a[i++];    //These lines occur after the lower numbers have been entered into C
    while(j < n)
        c[k++] = b[j++];    //This will add the elements that are left.
}
