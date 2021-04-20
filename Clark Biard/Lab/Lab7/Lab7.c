#include "Lab7.h"

void charges(double hours, double *avg, double *cost)
{
	if (hours <= 10)
	{
		*cost = 7.99;
		*avg = 7.99;
	}
	else
	{
		*cost = ((hours - 10) * 1.99) + 7.99;
		*avg = *cost / hours;
	}
}

double round_money(double money)
{
	double value = (int)(money * 100 + .5);
	return (double)value / 100;
}

void predict(int value, FILE* Revenues)
{
	double revenue = 0.0;
	for (int i = 1984; i < 2021; i++)
	{
		revenue = pow(1.071, ((double)i - 1984)) * 203.265;
		printf("Revenue: %lf\n", revenue);
		if (revenue >= (double)value)
		{
			fprintf(Revenues, "%d ", i);
			fprintf(Revenues, "%.2lf", revenue);
			fprintf(Revenues, "(millions)\n");
		}
	}
}
