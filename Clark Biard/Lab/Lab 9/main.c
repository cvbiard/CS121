#include "header.h"

int main(void)
{

	char word[] = "CptS 121 is cool!";
	char copy[] = "CptS 121 is cool!";

	//Problem 1, see protos for regular and pointer notation versions
	//reverse_string(word);

	//Problem 2
	//a.
	//my_strcpy(copy, word);
	//b.
	//my_strcat(copy, word);
	//c.
	//printf("Return is %d.\n", my_strcmp(word, copy));
	//d.
	printf("Return is %d.\n", my_strlen(word));
	return 0;
}