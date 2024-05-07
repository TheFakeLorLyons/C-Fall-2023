/* From a book on C ~456ish */

#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "stack.h"

LINK   string_to_list(char []);
void   print_list(LINK);
int    count_it(LINK);

int main(void)
{
   char    str[] = "My name is Joanna Kelley!";
   int     i;
   stack   s;
   LINK    h, string2;

   h = string_to_list("ABC");
   printf("The resulting list is\n");
   print_list(h);
   printf("\nThis list has %d elements.\n", count_it(h));
   string2 = string_to_list("Am I programming?");
   concatenate(h, string2);
   printf("\nThis list has %d elements.\n", count_it(string2));
   printf("The resulting list is\n");
   print_list(string2);

   printf("\n");

   initialize(&s);                      /*initialize the stack */
   printf(" In the spring: %s\n", str);
   for (i = 0; str[i] != '\0'; ++i)
      if (!full(&s))
          push(str[i], &s);          /* push a char on the stack */
   printf("From the stack: ");
   while(!empty(&s))
      putchar(pop(&s));              /* pop a char off the stack */
   putchar('\n');
   return 0;
}
