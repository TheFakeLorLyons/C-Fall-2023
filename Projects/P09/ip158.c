/*               ip158.c
 *                  By Lorelai Lyons
 *                    Entered November 27, 2023
 *
 *
 *    This program will take an IP Address and subnet mask
 *    and return a network address in both binary and CIDR format.
 *
 */

#include <stdio.h>   //Standard pre processing directives
#include <stdlib.h>

#include "ipfunc.h"

int main(void)
{                    /* Declaring local variables */
   char c, ipAddress[15] = {0}, subNet[15] = {0}, bitArray[32]; //IP and subnet entered as strings

   int  i, subInt, ipInt, netAdd;       //The strings will be turned to ints to be turned to binary

   printf("\n %s\n\n %s\n %s\n %s\n\n %s",
          "Welcome to ip158.",                    /* Program introduction */
          "This program will display the IP address and subnet mask in binary",
          "format.  It will also display the network address in binary and in",
          "CIDR formats",
          "Enter an IP address: ");      //Prompt user input

   scanf("%s", &ipAddress);              //User entry for IP Address

   if(ipVal(ipAddress) == 1)            //Validate user entry with ipVal function
   {
      printf("\n The ip address you entered (%s) is not valid. \n\n", ipAddress);
      exit(1);
   }

   /* The getBinary function takes the already validated IP Address, and converts
    * the numbers into a packed integer that stores the values in binary */
   ipInt = getBinary(ipAddress);

   printf(" Enter the subnet mask: ");   //User entry for subnet mask

   scanf("%s", &subNet);

   /* Sub val validation here */
   if(subVal(subNet) == 1)            //Validate user entry with ipVal function
   {
      printf("\n The subnet address you entered (%s) is not valid. \n\n", subNet);
      exit(1);
   }

   /* Again, the getBinary function converts the string into a packed, unsigned
    * integer. It needs to be unsigned so that we can print it with bit_print()*/
   subInt = getBinary(subNet);

   printf("\n IP Address:  ");   //Printing out the IP address info
   bit_print(ipInt);               //..in binary
   printf("   %s", ipAddress);     //..in dotted decimal

   printf("\n Subnet Mask: ");   //Printing out the subnet mask info
   bit_print(subInt);              //..in binary
   printf("   %s", subNet);        //..in dotted decimal

   netAdd = (ipInt & subInt);    //And statement contructs the Network Address

   printf("\n Network Add: ");   //Printing out the "anded" network address
   bit_print(netAdd);              //..in binary
   //printf("%d", netAdd);
   /* prints the ip address back in dotted decimal, with the CIDR at the end. */
   getDottedIp(netAdd);
   printf("/%d\n", cmpCIDR(subInt));

   printf("\n Thank you for using ip158.\n\n");  //end of the program

   return 0;
}
