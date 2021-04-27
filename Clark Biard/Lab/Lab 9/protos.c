#include "header.h"

void reverse_string(char string[])
{
	char low = '\0', high = '\0';

	int length = 0;

	while (string[length] != "\n")
	{
		length = length + 1;
	}

	printf("Length is %d.\n", length);

	for (int i = 0; i < length/2; i++)
	{
		low = string[i];
		high = string[(length-1) - i];

		printf("Low is %c and high is %c.\n", low, high);
	
		string[i] = high;
		string[(length-1) - i] = low;
	}

	for (int j = 0; j < length; j++)
	{
		printf("%c", string[j]);
	}

}