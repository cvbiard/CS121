#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <stdarg.h>

double read_number(FILE*infile);
double calc_average(double sum,int count);
double print_number(FILE*outfile, double value);