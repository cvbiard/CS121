#include "Lab5.h"

int read_number(FILE* infile)
{
	int info = 0;
	fscanf(infile, "%d", &info);
	return info;
}
int print_number(FILE* outfile, int number)
{
	fprintf(outfile, "%d", number);
}

int greatest_common_divisor(int number1, int number2)
{
	int division = 0, remainder = 1, prev = 0;

	while (remainder !=0)
	{	
		remainder = number1%number2;

		//printf("Division: %d\n", division);
		//printf("Remainder %d\n", remainder);

		number1 = number2;
		number2 = remainder;
	}
	return number1;
}