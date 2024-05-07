#include <stdlib.h>
#include "list.h"

LINK string_to_list(char s[])
{
   LINK   head;

   if (s[0] == '\0')    /* base case */
      return NULL;
   else {
      head = malloc(sizeof(ELEMENT));       /*A link is a pointer to struct ELEMENT,
                                              which is a type of struct that contains
                                              itself a char(in this case), and also a
                                              pointer to the address of the next ELEMENT.*/

      head -> d = s[0];                     /*This line points to the data member of the LINK,
                                              and assigns that value the 0th value of the input
                                              string.*/

      head -> next = string_to_list(s + 1); /*Once the character value is written, it will point
                                              to the address of the next LINK in the ELEMENT.*/

      return head;                          //Returning the address of the next LINK
   }
}
