/*                    main.c
 *                       entered by Lorelai Lyons
 *                       October 24.2023
 *
 *   Program Assignment: A07
 *   Due Date: October 27, 2014

 *   From A Book on C, Page 269
 *
 *   Part of 6.9, An Example of Merge and Merge Sort - Pages 263-269
 *
 */

/* Test merge() and mergesort(). */   //This comment is from the book.

#include "mergesort.h"      //Including the header file for all function definitions.

int main(void)              //Beginning of the main function.
{
//  int sz, key[] = { 4, 3, 1, 67, 55, 8, 0 ,4,   //Declaring and assigning local variables.
//                   -5, 37, 7, 4, 2, 9, 1, -1, 12  };
    int sz, key[] = { 4, 3, 1, 67, 55, 8, 0 ,4,   //Declaring and assigning local variables.
                     -5, 37, 7, 4, 2, 9, 1  };

    sz = sizeof(key) / sizeof(int);  /* the size of key */
    printf("Before mergesort:\n");   //Printing to output.
    wrt(key, sz);                    //Calling the function 'wrt' with the arguments key and sz.
    mergesort(key, sz);              //Calling the function 'mergesort' to sort the array.
    printf("After mergesort:\n");    //Printing to output.
    wrt(key, sz);                    //Calling the function 'wrt' again.
    return 0;                        //End of the main function.
}
