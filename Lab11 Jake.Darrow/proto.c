#include "header.h"

double read_double(FILE* name)
{
	double vari = 0.0;
	fscanf(name, "%lf", &vari);
	return vari;
}

void print_double(FILE* outfile, double number)
{
	fprintf(outfile, "%lf", number);
}