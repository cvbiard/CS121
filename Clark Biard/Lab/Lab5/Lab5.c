#include"Lab5.h"

double read_salary(FILE* infile)
{
	double info = 0.0;
	fscanf(infile, "%lf", &info);
	return info;
}
double sum(double qs1, double qs2, double qs3, double qs4)
{
	return (qs1 + qs2 + qs3 + qs4);
}
char determine_bracket(double sum)
{
	if (sum < 15000)
	{
		return 'l';
	}
	if (sum > 15000 && sum < 200000)
	{
		return 'm';
	}
	if (sum > 200000)
	{
		return 'h';
	}
}