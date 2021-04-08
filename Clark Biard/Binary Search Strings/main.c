#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int binary_search(char list[10][15], char target[]);
int binary_search(char list[100][15], char target[])
{
	int left_index = 0, right_index = 99, mid_index = 0, size = sizeof(target),
		found = 0, match = 0;

	while (!found && left_index <= right_index)
	{
		mid_index = (right_index + left_index) / 2;
		if ((int)list[mid_index][0] == (int)target[0])
		{
			for (int i = 0; i < size; i++)
			{
				if ((int)list[mid_index][i] == (int)target[i])
				{
					match = match + 1;
					if (match == size)
					{
						found = 1;
						return mid_index;
					}
				}
			}
		}
		else if ((int)list[mid_index][0] > (int)target[0])
		{
			right_index = mid_index - 1;
		}
		else
		{
			left_index = mid_index + 1;
		}

	}
	return -1;
}
int main()
{
	char list[10][15] = { "aaaa", "bbbb", "cccc", "dddd", "eeee", "ffff", "gggg", "hhhh", "iiii", "jjjj" };
	char target[] = "kkkk";
	int find = 0;

	find = binary_search(list, target);
	printf("%d\n", find);
	return 0;
}