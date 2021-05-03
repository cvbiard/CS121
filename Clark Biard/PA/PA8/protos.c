#include "header.h"

char* my_str_n_cat(char* destination, char* source, int n)
{
	int length = 0;

	while (*(destination + length) != NULL)
	{
		length = length + 1;
	}

	for (int i = length; i < (length + n); i++)
	{

		if (*(source + (i - length)) == NULL)
		{
			break;
		}
		*(destination + i) = *(source + (i - length));
	}

	return destination;
}
int binary_search(int target, int sorted_arr[], int arr_size)
{
	int low_index = 1, mid_index = 0, high_index = arr_size, mid_val = 0, found = 0;

	while (found != 1 && low_index <= high_index)
	{
		mid_index = (high_index + low_index) / 2;

		mid_val = sorted_arr[mid_index];

		if (target > mid_val)
		{
			low_index = mid_index + 1;
		}
		if (target < mid_val)
		{
			high_index = mid_index - 1;
		}
		if (target == mid_val)
		{
			found = 1;
			printf("Target found at index %d.\n", mid_index);
			return mid_index;
		}
	}

	printf("Target not found.");
	return 0;
}
void bubble_sort(char** words, int size)
{
	int index = 0, passes = 0;

	char* temp;

	for (passes = 1; passes < size; ++passes)
	{
		for (index = 0; index < size - passes; ++index)
		{
			if (strcmp((*(words + index) + 0), (*(words + (index + 1)) + 0)) > 0)
			{
				temp = *(words + index) + 0;
				*((words + index) + 0) = *(words + (index + 1)) + 0;
				*((words + (index + 1)) + 0) = temp;
			}
		}
	}
}
int is_palindrome(char* string, int start, int length)
{
	if (start == length)
	{
		return 1;
	}

	if (*(string + start) != *(string + length))
	{
		return 0;
	}

	if (start < length + 1)
	{
		return is_palindrome(string, start + 1, length - 1);
	}

	return 1;
}
int sum_primes(unsigned int n)
{
	int sum = 0;
	
	if (n > 1)
	{
		printf("looking at %d.\n", n);
		sum = sum_primes(n - 1);
	}

	int m = n / 2;
	for (int i = n; i == 2; i--)
	{
		if (n % i == 0)
		{
			printf("%d was not prime.\n", n);
			break;
		}
	}
	
	printf("%d was prime!\n", n);
	return sum + n;

}