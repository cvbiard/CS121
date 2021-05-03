#include "header.h"

int main(void)
{
	int count = 0;
	FILE* input = fopen("payroll.txt", "r"), * output = fopen("paid.txt", "w");

	Employee payroll[200]; // the input file may not exceed 200 employee records

	Totals total;
	total.total = 0.0;
	total.average = 0.0;
	total.max = 0.0;
	total.min = 0.0;

	Totals arr[1] = {total};

	count = read_info(input, payroll);
	compute(payroll, count, arr);
	print_info(output, arr);
	fclose(input);
	fclose(output);
	return 0;
}