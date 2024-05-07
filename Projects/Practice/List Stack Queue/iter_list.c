/*List creation using iteration */

/* From 'A Book on C' 1998 pg 453 */

#include <stdio.h>                         /*Preprocessing directives*/
#include <stdlib.h>

#include "list.h"

LINK s_to_l(char s[])                 //function header, take a char array 's'
{
   LINK    head  = NULL, tail;        //Two links, one null (the head) we
   int i;                             //start with the tail

   if (s[0] != '\0') {                     /* First element */
                                        //If first element is NOT empty THEN...
      head = malloc(sizeof(ELEMENT));     //Go ahead and place data in the head
      head -> d = s[0];
      tail = head;                        //tail is assigned  the value of head?
      for (i = 1; s[i] != '\0'; ++i) {     /* Add to tail */
                                         //As long as the NEXT LINK isn't empty THEN..
       tail -> next = malloc(sizeof(ELEMENT));//Continue through, appending the string
       tail = tail -> next;
       tail -> d = s[i];
      }
      tail -> next = NULL;                 /* End of list */
    }
    return head;
}

