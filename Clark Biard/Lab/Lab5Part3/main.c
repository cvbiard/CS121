#include "Lab5.h"

int main(void)
{
	FILE* infile = fopen("input.txt", "r");
	FILE* outfile = fopen("output.txt", "w");
	int number1 = 252, number2 = 735, gcd = 0;

	gcd = greatest_common_divisor(number1, number2);

	print_number(outfile, gcd);
}