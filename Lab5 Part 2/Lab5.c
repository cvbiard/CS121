#include "Lab5.h"

double read_number(FILE*infile)
{
	double info = 0.0;
	fscanf(infile, "%lf", &info);
	return info;
}
double calc_average(double sum, int count)
{
	return sum / count;
}
double print_number(FILE* outfile, double value)
{
	fprintf(outfile, "%.2lf", value);
}