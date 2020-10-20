#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// function declaration - function prototype
// introducing a user defined function that is not found in
// a standard library

// what is the output of the function? what are the inputs 
// to the function? what is the anme of the function?
int get_credits(int class_number);
// precondition: file must be open!
int read_credits(FILE *input_file);
// precondition: file must be open!
double read_gp(FILE* input_file);
double compute_gpa(double wgp, int sum);
