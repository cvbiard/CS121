#include "header.h"

//char *reverse_string(char string[])
//{
//	char low = '\0', high = '\0';
//
//	int length = 0;
//
//	while (string[length] != NULL)
//	{
//		length = length + 1;
//	}
//
//
//	for (int i = 0; i < length/2; i++)
//	{
//		low = string[i];
//		high = string[(length-1) - i];
//
//	
//		string[i] = high;
//		string[(length-1) - i] = low;
//	}
//
//	for (int j = 0; j < length; j++)
//	{
//		printf("%c", string[j]);
//	}
//
//	return string;
//}

char* reverse_string(char *string[])
{
	char low = '\0', high = '\0';

	int length = 0;

	while (*(string+length) != NULL)
	{
		length = length + 1;
	}

	printf("Length is %d.\n", length);

	for (int i = 0; i < length / 2; i++)
	{
		low = *(string+i);
		high = *(string+((length - 1) - i));

		printf("Low is %c and high is %c.\n", low, high);

		*(string+i) = high;
		*(string + ((length - 1) - i)) = low;
	}

	for (int j = 0; j < length; j++)
	{
		printf("%c", string[j]);
	}

	return string;
}
char* my_strcpy(char* destination, const char* source)
{
	int length = 0;

	while (*(source + length) != NULL)
	{
		length = length + 1;
	}

	for (int i = 0; i < length; i++)
	{
		*(destination + i) = *(source + i);
	}

	for (int j = 0; j < length; j++)
	{
		printf("%c", destination[j]);
	}

	return destination;
}
char* my_strcat(char* destination, const char* source)
{
	int length_source = 0, length_destination = 0;

	while (*(source + length_source) != NULL)
	{
		length_source = length_source + 1;
	}

	while (*(source + length_destination) != NULL)
	{
		length_destination = length_destination + 1;
	}

	for (int i = length_destination; i < length_source + length_destination; i++)
	{
		*(destination+i) = *(source+i - length_destination);
	}

	for (int j = 0; j < length_source + length_destination; j++)
	{
		printf("%c", destination[j]);
	}

	return destination;
}
int my_strcmp(const char* s1, const char* s2)
{
	int length1 = 0, length2 = 0, max = 0;

	while (*(s1 + length1) != NULL)
	{
		length1 = length1 + 1;
	}

	while (*(s2 + length2) != NULL)
	{
		length2 = length2 + 1;
	}

	if (length1 > length2)
	{
		max = length1;
	}
	else
	{
		max = length2;
	}

	for (int i = 0; i < max; i++)
	{
		if ((int)*(s1 + i) > (int)*(s2 + i))
		{
			return 1;
		}
		if ((int)*(s1 + i) < (int)*(s2 + i))
		{
			return -1;
		}
	}
	return 0;
}
int my_strlen(const char* s)
{
	int length = 0;

	while (*(s + length) != NULL)
	{
		length = length + 1;
	}
	return length;
}