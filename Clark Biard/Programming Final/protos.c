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
		printf("Name: %s\n", customers[i].name);
		printf("Plan: %c\n", customers[i].plan);
		printf("Talk in minutes: %d\n", customers[i].talk_minutes);
		printf("Data in MB: %d\n", customers[i].data_MB);
		printf("Charges: %lf\n", customers[i].charges);
		printf("Order: %d\n", customers[i].order);
		printf("\n");
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
		dummies[customers[i].order] = customers[i];
	}
	for (int i = 0; i < 100; i++)
	{
		customers[i] = dummies[i];
	}
}