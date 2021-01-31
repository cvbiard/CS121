#include "header.h"

int main()
{
	FILE* infile = fopen("customers.txt", "r"), *outfile = fopen("charges.txt", "w");
	Profile customers[100];
	Profile dummies[100];

	Profile dummy = { "dummy", 'A', 0, 0, 0.0, 0, 1, 0.0 };
	
	init_arr(dummy, customers);
	init_arr(dummy, dummies);
	read_customers(infile, customers);
	sort_customers(customers, dummies);
	calculate_charges(customers);
	print_customers(customers);
	calculate_stats(customers, outfile);

	fclose(infile);
	fclose(outfile);
	return 0;
}