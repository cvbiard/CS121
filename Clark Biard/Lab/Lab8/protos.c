#include "header.h"

void read_to_array(int arr[], FILE* input)
{
	int current = 0, index = 0;
	while(current = fscanf(input, "%d", &arr[index]) >=0)
	{
		printf("current at %d is %d.\n", index, current);
		index = index + 1;
	}

	for (int i = 0; i < 6; i++)
	{
		printf("Number %d is %d.\n", i, arr[i]);
	}
} 