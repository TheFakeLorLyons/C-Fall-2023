/*From 'A Book on C' page */

#include <stdio.h>                       /*Preprocessing directives*/
#include <stdlib.h>

typedef   char   DATA;                   /* will use char in examples */

struct linked_list {
   DATA                d;                //The list contains character data
   struct linked_list  *next;            //...and the address of the next data
};

typedef   struct linked_list  ELEMENT;   //Element contains DATA and the pointer to *next. It  is a type of the structure.
typedef   ELEMENT             *LINK;     //*LINK is a pointer of type element. It points to the head of the link? The address...
