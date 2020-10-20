#include "gpa.h"

int get_credits(int class_number) // function header
{
	// function definition - determine all the function does
	// 1 algorithm
	// solving 1 problem - subproblem

	// local varaible to get_credits () - can't
	// be accessed outside of get_credits ()
	int credits = 0;
	// 1. Prompt the user for the credits for class
	printf("Enter credits possible for class %d: ",
		class_number);
	// 2. Get the credits for class from the user
	scanf("%d", &credits);

	return credits; // make a copy of the value stored in credits
} // end of get_credits ()

// precondition: file must be open!
int read_credits(FILE* input_file)
{
	int credits = 0;
	fscanf(input_file, "%d", &credits);
	return credits; // copy of value read from file
}

// precondition: file must be open!
double read_gp(FILE* input_file)
{
	double gp = 0.0;
	fscanf(input_file, "%lf", &gp);
	return gp;
}

double compute_gpa(double wgp, int sum)
{
	return (wgp / sum);
}