#include "Lab7.h"
int main(void)
{
	FILE *input = NULL;
	FILE *output = NULL;

	input = fopen("input.txt", "r");
	output = fopen("output.dat", "w");

	int count = 0, month = 0, year = 0,  number = 0;
	double avg, cost, rounded, hours;


	while (!feof(input))
	{
		if (count == 0)
		{
			fscanf(input, "%d%d", &month, &year);
			fprintf(output, "Month is %d, year is %d\n", month, year);
			count = count + 1;
		}
		else
		{
			fscanf(input, "%d ", &number);
			fprintf(output, "%d ", number);
			
			fscanf(input, "%lf", &hours);
			charges(hours, &avg, &cost);
			rounded = round_money(cost);
			fprintf(output, "%.2lf\n", rounded);
			count = count + 1;
		}

	}
	return 0;
}