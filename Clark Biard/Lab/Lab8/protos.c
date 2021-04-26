#include "header.h"

void read_to_array(int arr[], FILE* input)
{
	int current = 0, count = 0;
	while (fscanf(input, "%d", &current) >= 0)
	{
		count = count + 1;
	}

	rewind(input);

	arr = malloc(sizeof(int)*count);
	
	printf("Count is %d.\n", count);

	for (int i = 0; i < count; i++)
	{
		rewind(input);
		fseek(input, (((count)*2)-2)-(2*i), SEEK_SET);
		fscanf(input, "%d", &arr[i]);
	}

	for (int j = 0; j < count; j++)
	{
		printf("%d is %d.\n", j, arr[j]);
	}
}
void populate_array(int arr[])
{
	for (int i = 0; i < 20; i++)
	{
		arr[i] = (rand() % 99) + 1;
	}
}
void frequency(int arr[], int ft[])
{

	for (int j = 0; j < 101; j++)
	{
		ft[j] = 0;
	}
	for (int i = 0; i < 20; i++)
	{
		ft[arr[i]] = ft[arr[i]] + 1;
	}
}
void print_arr(int arr[], int number)
{
	for (int i = 0; i < number; i++)
	{
		printf("Array at %d is %d.\n", i, arr[i]);
	}
}