/*                       mergesort.c
 *                            entered by
 *                            October 24.2023
 *
 *   Program Assignment: A07
 *   Due Date: November 11, 2023

 *   From A Book on C, Page 269
 *
 *   Part of 6.9, An Example of Merge and Merge Sort - Pages 263-269
 *   This is the only file I edited for this project. My solution used
 *   an integer to calculate the leftover number of numbers. After
 *
 */

/* Merge a[] of size m and b[] of size n into c[].*/

#include "mergesort.h"
void mergesort(int key[], int n)
{
   int j, k, new, *w;

   w = calloc(n, sizeof(int));            /* allocate workspace */
   assert(w != NULL);              /*check that calloc() worked */

   /*Here I removed several lines of code that would close the code
     on the condition that the number of elements in key[] were
     greater than m, and that is no longer necessary here.*/

   for(k = 1; k < n; k *= 2)
   {
      for(j = 0; j <= n - (k*2); j += 2 * k)
         /*
         // Merge two subarrays of key[] into a subarray of w[].
         */
         merge(key + j, key + j + k, w + j, k, k);//Calling merge fuction, this was here.

      new = n % (2 * k); //The integer new calculates the leftover numbers from key if k is not an exact power of 2

      for(j = 0; j < n-new; ++j)//This sorts through the numbers that are leftover (if there are any, if not, new will be 0 and it will copy the whole array.
         key[j] = w[j];    //Appending the leftover numbers onto the memory location of *w[j](This would be next to the last numbers placed at w[])

       /*This section will only occur if there were leftover numbers above.
        *The numbers that were leftover are merged and appeneded to w,
        *which is both an identifier for the beginning of the return array,
        *and a pointer to the first index of it. */
      if(new != 0 && new < n)
      { //If the leftover is not an even 0 after being divided from k.
         merge(key + n - (2*k) - new, key + n-new, w + n - (2 * k) - new, 2 * k, new);//then merge them with the established numbers.
         for(j = n - (2 * k) - new; j < n; ++j)
         {
             key[j] = w[j];//Placing the newly merged numbers into the final array
         }
      }
   }
   free(w);                               /* free the workspace */
}
