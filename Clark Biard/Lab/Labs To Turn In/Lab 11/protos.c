#include "header.h"

int read_info(FILE* input, Employee payroll[200])
{
	int count = 0;
	int char_count = 0;
	char temp_str[20];
	while (!feof(input))
	{
		fscanf(input, "%s", &payroll[count].name);	
		fscanf(input, "%s%*c", &temp_str);
		strcat(payroll[count].name, temp_str);

		printf("%s\n", payroll[count].name);
		fscanf(input, "%c", &payroll[count].title);
		printf("%c\n", payroll[count].title);
		fscanf(input, "%lf", &payroll[count].hours_worked);
		printf("%lf\n", payroll[count].hours_worked);
		fscanf(input, "%lf", &payroll[count].payrate);
		printf("%lf\n", payroll[count].payrate);
		count = count + 1;
	}

	return count;
}
void compute(Employee payroll[200], int count, Totals arr[1])
{
	double payment = 0.0, overtime = 0.0;
	for (int i = 0; i < count; i++)
	{
		if (payroll[i].hours_worked > 40)
		{
			if (payroll[i].title == 'B')
			{
				overtime = ((payroll[i].hours_worked - 40) * (1.5 * payroll[i].payrate));
			}
			if (payroll[i].title == 'M')
			{
				overtime = ((payroll[i].hours_worked - 40) * (1.8 * payroll[i].payrate));
			}

			payment = (40 * payroll[i].payrate);

			payroll[i].payment = payment + overtime;
		}
		else
		{
			payroll[i].payment = (payroll[i].hours_worked * payroll[i].payrate);
		}

		if (i == 0)
		{
			arr[0].min = payroll[i].payment;
		}

		arr[0].total = arr[0].total + payroll[i].payment;
		if (arr[0].min > payroll[i].payment)
		{
			arr[0].min = payroll[i].payment;
		}
		if (arr[0].max < payroll[i].payment)
		{
			arr[0].max = payroll[i].payment;
		}
		overtime = 0.0;
		payment = 0.0;
	}
	arr[0].average = arr[0].total / count;
}
void print_info(FILE* output, Totals arr[1])
{
	fprintf(output, "Total: $%.2lf\n", arr[0].total);
	fprintf(output, "Average: $%.2lf\n", arr[0].average);
	fprintf(output, "Max: $%.2lf\n", arr[0].max);
	fprintf(output, "Min: $%.2lf\n", arr[0].min);
}