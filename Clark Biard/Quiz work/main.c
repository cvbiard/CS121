#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
int reverse_arr(int arr[100][5], int rows, int columns)
{
	int low = 0, high = 0;

	for (int k = 0; k < rows; k++)
	{
		for (int i = 0; i < columns / 2; i++)
		{
			low = arr[k][i];
			high = arr[k][((columns - 1) - i)];


			arr[k][i] = high;
			arr[k][((columns - 1) - i)] = low;
		}


	}

	for (int j = 0; j < rows; j++)
	{
		for (int l = 0; l < columns; l++)
		{
			printf("%d ", arr[j][l]);

		}
		printf("\n");

	}

	
	return 0;
}
int reverse_arr(int arr[100][5], int rows, int columns);
void recursive_string_copy(char* source[], char* dest[], int count)
{
	if (*(source + count) != NULL)
	{
		*(dest + count) = *(source + count);
		count = count + 1;
		recursive_string_copy(source, dest, count);
	}
}

char* reverse_string(char string[], int length, int count)
{
	char low = '\0', high = '\0';

	if (count < length / 2)
	{
		low = *(string + count);
		high = *(string + ((length - 1) - count));

		printf("Low is %c and high is %c.\n", low, high);

		*(string + count) = high;
		*(string + ((length - 1) - count)) = low;
		count = count + 1;

		reverse_string(string, length, count);
	}
	else
	{
		return string; 
	}
	

	return string;

}
int main(void)
{
	int arr[2][5] = { {0, 1, 2, 3, 4}, {0, 1, 2, 3, 4} };

	char string[4] = "lost";
	char dest[4] = "dest";

	//reverse_arr(arr, 2, 5);
	//reverse_string(string, 4, 0);
	recursive_string_copy(string, dest, 0);

	for (int j = 0; j < 4; j++)
	{
		printf("%c", dest[j]);
	}
	return 0;
}
