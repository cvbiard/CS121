#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void recursive_string_copy(char *destination, char *source)
{
		if (*source)
		{
			*destination = *source;
			recursive_string_copy(destination + 1, source + 1);
		}
}

int main(void)
{
	//declaration of 2 character arrays
	char s[20], d[20];
	//Prompt the user to enter a string
	printf("Enter a string: ");
	//reads the string until a new line
	gets(s);
	//function call
	recursive_string_copy(d, s);
	//Display strings
	printf("\nSource string: %s\n\n", s);
	printf("Destination string: %s\n\n", d);
	printf("\n");
	return 0;
}