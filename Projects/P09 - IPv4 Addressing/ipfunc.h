/*                ipfunc.h
 *                  By Lorelai Lyons
 *                     Entered  November 1, 2023
 *
 *  This header file contains all of the functions necessary for me to run through
 *  the main function and take user input to compare the two header files.
 *
 *  The top 5 were in the directions, and my best attempt at producing the intended output
 *  utilized 4 other functions.
 *
 *  The 4 functions I added:
 *
 *    cidrSwitch:    Returns the allowed values for a subnet mask for validation.
 *    octsToAddress: This is just a micro function to pack the output of getBinary into an int
 *    getBinary:     This function essentially converts a string to an unsigned integer, but it
 *                   does so by reading through the string to specifically avoid the '.' characters
 *                   and pack the smaller octets into one output int.
 *    getDottedIP:   At the end of main we need to produce the corresponding dotted decimal notation
 *                   for the network address produced by user input. This function does that by taking
 *                   an unsigned int made by applying an 'and' comparison to the IP Address and Subnet
 *                   mask.
 *
 */

unsigned pack(int networkID1, int networkID2, int hostID1, int hostID2);
int    unpack(unsigned address, int choice);
int     ipval(char *ipAddress);
int    subval(char *ipAddress);
int   cmpCIDR(unsigned mask);
int         cidrSwitch(int octetVal); //octetVal is the 1-3 digit number between each period in an IP Address or subnet mask.
unsigned octsToAddress(int octs[4]);  //octs is an array of 4 integers that I pass into the pack function.
int          getBinary(char *ipInput);//This function produces the octs array that packs the bits into a 32 bit integer.
void       getDottedIP(unsigned binAdd);//binAdd is