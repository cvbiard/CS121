#include "header.h"

void read_to_array(int arr[], FILE* input)
{
	int current = 0, count = 0;
	while (fscanf(input, "%d", &current) >= 0)
	{
		count = count + 1;
	}

	rewind(input);

	arr[0] = malloc(sizeof(int)*count);
	
	for (int i = 0; i < count; i++)
	{
		fscanf(input, "%d", &arr[i]); 
	}

	for (int i = 0; i < 5; i++)
	{
		printf("Number %d is %d.\n", i, arr[i]);
	}

}