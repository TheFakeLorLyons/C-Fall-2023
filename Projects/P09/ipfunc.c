/*          ipfunc.c
 *            By Lorelai Lyons
 *              Entered on 11/27/2023
 *
 *   This is the helper file for my ip158 project.
 *
 *   This file will contain the source code for functions that will
 *   be included in the header file ipfunc.h and called in ip158.c.
 *
 *   The pack function will take 4 numbers and create a packed unsigned integer to
 *   represent the IP Adress and Subnet Mask.
 *
 *   The unpack function will take a specified octet and return the value between
 *   0 and 255.
 *
 *   The ipVal function will determine whether or not an ipAddress is valid.
 *
 *   The subVal function will determine whether or not the subnet mask is valid.
 *
 *   Finally, the cmpCIDR function will count the number of bits that are consecutively
 *   turned on beginning on the left hand side of the subnet mask.
 *
 */

#include <limits.h> //Allows use of the CHAR_BIT macro.
#include <stdio.h>  //Allows use of the NULL macro.
#include <stdlib.h> //Allows calloc.

#include "ipfunc.h" //Including the header file.


#define toDigit(c)(c-'0')//This short macro allows easy conversion between chars and ints.


/* The pack function takes 4 integers and 'packs' them into ONE 32 bit unsigned integer */
unsigned pack(int networkID1, int networkID2, int hostID1, int hostID2)
{
   unsigned ipInt, i = 0;
   int      convergInt[4];

   /* The four integers are placed into an array of integers */
   convergInt[0] = networkID1;
   convergInt[1] = networkID2;
   convergInt[2] = hostID1;
   convergInt[3] = hostID2;

   for( ; i < 4; i++)  /* This checks each value */
   {
      if(convergInt[i] < 0 || convergInt[i] > 255)
         return -1;   /* Exits if too great or small */
   }

   i = 1;
   ipInt = convergInt[0];

   /* This for loop does the actual packing into the int */
   for( ; i < 4; i++)
   {
      ipInt = (ipInt << CHAR_BIT) | convergInt[i];
   }

   return ipInt;//Returns the packed integer to the calling function.
}

/* The unpack function takes a full packed integer, and unpacks the
 * component packed integers within. */
int unpack(unsigned address, int choice)
{
   int octReturn = ((choice - 1) * CHAR_BIT);
   unsigned        mask = 255;

   mask <<= octReturn;
   return ((address & mask) >> octReturn);
}


/* This function validates any entered IP Address in order to ensure it is accurate. */
int ipVal(unsigned char *ipAddress)
{
   int i = 0, numCh = 0, octet = 0, build = 0, firstOct;;
   unsigned unsignedIP = getBinary(ipAddress);

   if(ipAddress == NULL)
      return 1;

   firstOct = unpack(unsignedIP, 4);
      if(firstOct < 1 || firstOct > 223)
      return 1;

   while(*ipAddress != '\0')
   {
      if(*ipAddress == '.')
      {
         if(numCh == 0 || ++octet == 4)
            return 1;

         numCh = build = 0;
         ipAddress++;
         continue;
      }

      if((*ipAddress < '0') || (*ipAddress > '9'))
         return 1;

      if((build = build * 10 + *ipAddress - '0') > 255)
         return 1;

      numCh++;
      ipAddress++;
   }

   if(octet != 3)
      return 1;
   if(numCh == 0)
      return 1;

   return 0;
}

/* This function validates subnet masks to ensure they are valid and accurate. */
int subVal(char *subNet)
{
   int      i = 0, zeroCount = 0, subArr[4],
            bitCount = 0, n = sizeof(int) * CHAR_BIT,
            comparison = 1 << (n-1);
   char bitStore[n];
   unsigned unsignedNet = getBinary(subNet);//using a function I made to get an unsigned int.

   if(subNet == NULL)   //returns -1 if it is null...
      return 1;

   /* Assigning each individual 8 bits to an element of an array so we can check their validity. */
   subArr[0] = unpack(unsignedNet, 4);
   subArr[1] = unpack(unsignedNet, 3);
   subArr[2] = unpack(unsignedNet, 2);
   subArr[3] = unpack(unsignedNet, 1);

   if((subArr[3] > subArr[2]) ||
      (subArr[2] > subArr[1]) ||
      (subArr[1] > subArr[0])) //Return invalid if any of the 2,3,4th elements
      return 1;                //are bigger than the precending ones.

   for(i = 1; i <= n; ++i) {
      (((unsignedNet & comparison) == 0) ? (bitStore[i-1] = '0') : (bitStore[i-1] = '1'));
      unsignedNet <<= 1;
   }

   /* If the first digit is a zero then it is an invalid mask. */
   if(bitStore[0] == '0')
      return 1;

   i = 0;

   /* If a zero occurs, it should be allowed, but every number thereafter should be a 0 as well or the mask is invalid. */
   while(bitStore[i] != '\0')
   {
      if((zeroCount > 0) && bitStore[i] == '1')
         return 1;
      if(bitStore[i] == '0')
      {
         zeroCount++;
      }
      i++;
   }


   for(i = 0; i < 4; i++)
   {
      if(cidrSwitch(subArr[i]) == -1 && cidrSwitch(subArr[i+1]) == 1)
      {
         printf("cidrSwitch detected invalid #: %d", subArr[i]);
         return 1;
      }
   }

   for(i = 1; i <= n; ++i) {
      (((unsignedNet & comparison) == 0) ? (bitStore[i-1] = '0') : (bitStore[i-1] = '1'));
      unsignedNet <<= 1;
   }

   return 0;
}


/* This function counts the number of 1's at the beginning of the subnet mask and returns that count. */
int cmpCIDR(unsigned mask)
{
   int i, bitCount = 0, n = sizeof(int) * CHAR_BIT, comparison = 1 << (n-1);
   char bitStore[n];

   /* This bit of code compares mask with comparison using 'and' and stores the comparison into bitStore */
   for(i = 1; i <= n; ++i) {
      (((mask & comparison) == 0) ? (bitStore[i-1] = '0') : (bitStore[i-1] = '1'));
      mask <<= 1;
   }
   i = 0;

   /* As soon as there is one zero, we can return them because there should be no 1's past that. */
   while(bitStore[i] != '\0')
   {
       if(bitStore[i] == '0')
          return bitCount;
       if(bitStore[i] == '1')
          bitCount++;

       i++;
   }

   return bitCount; //Returning the count of turned on bis to the calling function.
}

/* This function is a simple switch that helps to quickly validate the appropriate values of the subnet mask. */
int cidrSwitch(int octetVal)
{
   switch(octetVal)		 
   {
      case 0:
         return 1;
      case 128:
         return 1;
      case 192:
         return 1;
      case 224:
         return 1;
      case 240:
         return 1;
      case 248:
         return 1;
      case 252:
         return 1;
      case 254:
         return 1;
      case 255:
         return 1;
      default:
         return -1;//returns negative one if any numbers are inherently invalid. Otherwise it just says it is okay to proceed.
   }
}

/* This is called at the end of getBinary() in order to change a string to 4 packed ints.
 * This function takes the produced numbers from getBinary and just packs them and returns. */
unsigned octsToAddress(int octs[4])
{
   unsigned parsedIp;

   return parsedIp = pack(octs[0], octs[1], octs[2], octs[3]);
}

/*This function looks at a string format IP Address or subnet mask and returns an equivalent
 * unsigned integer that can then be unpacked from using the unpack function. */
int getBinary(char *ipInput)
{
   char tmpChar[3] = {0};
   int octs[4], i = 0, octetCount = 0, tmpi = 0, octetLength = 0;

   while(octetCount < 4) //The function iterates until an array holding 4 integers gets filled.
   {
      if(octetCount != 3)/*3 is a special case because the rest of the function uses the '.' character to
	                      determine when to increment octetCount. 0,1,2 will move on when hitting the period.
                          The case for 3 is dealt with below, and just iterates up to 4 to leave the while
                          loop when complete */
      {
         if(ipInput[i] != '.')
         {  //This temporary character array will store each sub integer in the main string being parsed.
            tmpChar[tmpi] = ipInput[i];
            tmpi++;
            octetLength++; //octetLength is used in a moment to recombine each individual character into a digit
         }

         i++;
      }

      if(ipInput[i] == '.')  //Since IP's/SM's have the format 'xxx.xxx.xxx.xxx' with possibly less numbers,
      {                      //This if else chain will determine the specific number to pass into our return.
         if(octetLength == 3)//The return is an array of integers with a varied length determined by how long
         {                   //each sub-segment is.
            octs[octetCount] = (toDigit(tmpChar[0]) * 100); //3 digit numbers hundereds place.
            octs[octetCount] += (toDigit(tmpChar[1]) * 10);   //..10's place
            octs[octetCount] += (toDigit(tmpChar[2]) * 1);    //...1's place
         }
         else if(octetLength == 2)                          //If it is a two digit number.
         {
            octs[octetCount] = (toDigit(tmpChar[0]) * 10);  //..10's place
            octs[octetCount] += (toDigit(tmpChar[1]) * 1);  //...1's place
         }
         else if(octetLength == 1)                          //If it is a single digit.
         {
            octs[octetCount] = (toDigit(tmpChar[0]) * 1);   //The only digit. toDigit was defined at the beginning for this.
         }

         octetCount++, octetLength = 0, tmpi = 0;   //Incrememnting octetCount is necessary to reach the loop exit point.
      }                                             //Every iteration must reset the length of the octet and tmpi counter.

      if((octetCount == 3))               //This case deals with the final number that does not have a '.' to signal it's end.
      {
         while((ipInput[i]) != '\0')      //Instead I used the end of the array.
         {
            if(ipInput[i] != '.')         //Same conditions as before (line 282)
            {
               tmpChar[tmpi] = ipInput[i];
               tmpi++;
               octetLength++;
            }

            i++;
         }

         if(octetLength == 3)              //This is the same as above, but for the last iteration.
         {
            octs[octetCount] = (toDigit(tmpChar[0]) * 100);
            octs[octetCount] += (toDigit(tmpChar[1]) * 10);
            octs[octetCount] += (toDigit(tmpChar[2]) * 1);
         }
         else if(octetLength == 2)
         {
            octs[octetCount] = (toDigit(tmpChar[0]) * 10);
            octs[octetCount] += (toDigit(tmpChar[1]) * 1);
         }
         else if(octetLength == 1)
         {
            octs[octetCount] = (toDigit(tmpChar[0]) * 1);
         }
         octetCount++, octetLength = 0, tmpi = 0;
      }
   }

   return octsToAddress(octs);//I only use this to pack bits; and I called a separate function to do it in this case.
}

/* This function returns the dotted decimal format of the final Network Address in the program.
 * We got binAdd in the main function in ip158.c in line 70 from 'netAdd'.
 * I used unpack to separate it into 4 distinct integers that I could then
 *  just print out with a printf() statement.*/
void getDottedIp(unsigned binAdd)
{
   int num1, num2, num3, num4;

   num1 = unpack(binAdd, 4);
   num2 = unpack(binAdd, 3);
   num3 = unpack(binAdd, 2);
   num4 = unpack(binAdd, 1);

   printf("   %d.%d.%d.%d", num1, num2, num3, num4);	
}   
