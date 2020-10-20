#include "Lab7.h"

void charges(double hours, double *avg, double *cost)
{
	if (hours <= 10)
	{
		*cost = hours * 7.99;
		*avg = 7.99;
	}
	else
	{
		*cost = ((hours - 10) * 1.99) + 79.90;
		*avg = *cost / hours;
	}
}

double round_money(double money)
{
	double value = (int)(money * 100 + .5);
	return (double)value / 100;
}