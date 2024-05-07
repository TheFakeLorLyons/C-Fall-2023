/*                   mergesort.h
 *                        entered by Lorelai Lyons
 *                        October 24.2023
 *
 *   Program Assignment: A07
 *   Due Date: October 27, 2014

 *   From A Book on C, Page 263
 *
 *   Part of 6.9, An Example of Merge and Merge Sort - Pages 263-269
 *
 */

#include <assert.h>  //Allowing access to the 'assert()' macro.
#include <stdio.h>   //Standard pre processing directives.
#include <stdlib.h>

void merge(int a[], int b[], int c[], int m, int n);//Merges 2 arrays of sizes m and n into a third, sorted array.
void mergesort(int key[], int n); //Calls the merge function on the entered array if it is of the apprriate size.
void wrt(int key[], int sz);//This function will print the array elements to standard output
