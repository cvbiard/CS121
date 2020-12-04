//Jake's 13th and final CptS 121 lab

#include "Lab13.header.h"

int main(void)
{
	//1. From Chapter 10 of Deitel and Deitel's C How to Program book. Write a program that right shifts an integer variable 4 bits.
	//	 The program should print the integer in bits before and after the shift operation. Does your system place 0s or 1s in the vacated bits?
	int value = 98;
	printf("Here is the integer before being shifted by 4: %d\n", value);
	
	shift_four(value);
	value = value >> 4; // right shift here.
	printf("Here is the integer after being shifted by 4\n");
	shift_four(value);
	return 0;
}
