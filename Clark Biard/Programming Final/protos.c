#include "header.h"

int init_arr(Profile dummy, Profile customers[100])
{
	for (int i = 0; i < 100; i++)
	{
		customers[i] = dummy;
	}
	return 0;
}
int print_customers(Profile customers[100])
{
	for (int i = 0; i < 100; i++)
	{
		if (customers[i].dummy_flag != 1)
		{
			printf("Name: %s\n", customers[i].name);
			printf("Plan: %c\n", customers[i].plan);
			printf("Talk in minutes: %d\n", customers[i].talk_minutes);
			printf("Data in MB: %d\n", customers[i].data_MB);
			printf("Charges: %.2lf\n", customers[i].charges);
			printf("Order: %d\n", customers[i].order);
			printf("Dummy flag: %d\n", customers[i].dummy_flag);
			printf("Average charge: %.2lf\n", customers[i].avg_charge);
			printf("\n");
		}
	}
	return 0;
}
int read_customers(FILE *infile, Profile customers[100])
{
	char firstname[50];
	for (int i = 0; i < 100; i++)
	{
		if (feof(infile) != 1)
		{

			fscanf(infile, "%s", &customers[i].name);
			fscanf(infile, "%s", &firstname);
			strcat(customers[i].name, " ");
			strcat(customers[i].name, firstname);
			fscanf(infile, "%*c%c", &customers[i].plan);
			fscanf(infile, "%d", &customers[i].talk_minutes);
			fscanf(infile, "%d", &customers[i].data_MB);
			customers[i].dummy_flag = 0;
		}
	}
	return 0;
}
int sort_customers(Profile customers[100], Profile dummies[100])
{
	int counter = 0;
	for (int i = 0; i < 100; i++)
	{	
		for (int j = 0; j < 100; j++)
		{
			if (i != j)
			{
				if ((int)customers[i].name[0] > (int)customers[j].name[0])
				{
					customers[i].order = customers[i].order + 1;
				}
				else if ((int)customers[i].name[0] < (int)customers[j].name[0])
				{
					customers[j].order = customers[j].order + 1;
				}
				else if ((int)customers[i].name[0] == (int)customers[j].name[0])
				{
					for (int k = 0; k < 100; k++)
					{
						if (((int)customers[i].name[k] != (int)customers[j].name[k]))
						{
							if ((int)customers[i].name[k] > (int)customers[j].name[k])
							{
								customers[i].order = customers[i].order + 1;
								break;
							}
							else if ((int)customers[i].name[k] < (int)customers[j].name[k])
							{
								customers[j].order = customers[j].order + 1;
								break;
							}
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < 100; i= i+2)
	{
		for (int j = 0; j < 100; j++)
		{
			if (customers[j].order == i)
			{
				customers[j].order = customers[j].order - counter;
			}
		}
		counter = counter + 1;
	}
	for (int i = 0; i < 100; i++)
	{
		dummies[99-customers[i].order] = customers[i];
	}
	for (int i = 0; i < 100; i++)
	{
		customers[i] = dummies[i];
	}
	return 0;
}
int calculate_charges(Profile customers[100])
{
	int over = 0, data_over = 0;
	for (int i = 0; i < 100; i++)
	{
		if (customers[i].plan == 'A')
		{

			over = customers[i].talk_minutes - 1000;

			if (over > 0)
			{
				customers[i].charges = customers[i].charges + (35 + (over * .50));
			}
			else
			{
				customers[i].charges = customers[i].charges + 35;
			}

			data_over = customers[i].data_MB - 10000;

			if (data_over > 0)
			{
				customers[i].charges = customers[i].charges + (25 + (data_over * .25));
			}
			else
			{
				customers[i].charges = customers[i].charges + 25;
			}
		}
		if (customers[i].plan == 'B')
		{
			over = customers[i].talk_minutes - 2000;

			if (over > 0)
			{
				customers[i].charges = customers[i].charges + (55 + (over * .40));
			}
			else
			{
				customers[i].charges = customers[i].charges + 55;
			}

			data_over = customers[i].data_MB - 20000;

			if (data_over > 0)
			{
				customers[i].charges = customers[i].charges + (30 + (data_over * .15));
			}
			else
			{
				customers[i].charges = customers[i].charges + 30;
			}
		}
		customers[i].avg_charge = customers[i].charges / 2;
	}
	return 0;
}
int calculate_stats(Profile customers[100], FILE *outfile)
{
	int counter = 0;
	double total = 0.0, average = 0.0, max = 0.0, min = 0.0;
	for (int i = 0; i < 100; i++)
	{
		if (customers[i].dummy_flag != 1)
		{
			min = customers[i].charges;
			break;
		}
	}
	for (int i = 0; i < 100; i++)
	{
		if (customers[i].dummy_flag != 1)
		{
			total = total + customers[i].charges;
			counter = counter + 1;
			if (max < customers[i].charges)
			{
				max = customers[i].charges;
			}
			if (min > customers[i].charges)
			{
				min = customers[i].charges;
			}
		}
	}
	average = total / counter;

	fprintf(outfile, "Total: $%.2lf\n", total);
	fprintf(outfile, "Average: $%.2lf\n", average);
	fprintf(outfile, "Max: $%.2lf\n", max);
	fprintf(outfile, "Min: $%.2lf\n", min);
	return 0;
}