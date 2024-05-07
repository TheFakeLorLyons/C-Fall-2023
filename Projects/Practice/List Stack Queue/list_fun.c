/* From a book on C pg 456 - 459 */

#include <assert.h>
#include <stdio.h>

#include "list.h"

int count_it(LINK head)
{
   int cnt = 0;

   for ( ; head != NULL; head = head -> next)
      ++cnt;
   return cnt;
}

void print_list(LINK head)
{
   if(head == NULL)
      printf("NULL");
   else {
      printf("%c --> ", head -> d);
      print_list(head -> next);
   }
}

/* Concatenate list a and b with a as head. */

void concatenate(LINK a, LINK b)
{
   assert(a != NULL);
   if (a -> next == NULL)
      a -> next = b;
   else
      concatenate(a -> next, b);
}

/*Inserting an element in a linked list. */

void insert(LINK p1, LINK p2, LINK q)
{
   assert(p1 -> next == p2);
   p1 -> next = q;       /* insert */
   q -> next = p2;
}
