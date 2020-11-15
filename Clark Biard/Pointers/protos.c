#include "header.h"
void print_array(int anarray[2][5])
{
	int x;
	for (int i = 0; i < 2; i++)
	{
		x = i;
		for (int i = 0; i < 5; i++)
		{
			printf("%d ", anarray[x][i]);
		}
		printf("\n");
	}
}
int change_array(int anarray[2][5])
{
	int x;
	for (int i = 0; i < 2; i++)
	{
		x = i;
		for (int i = 0; i < 5; i++)
		{
			anarray[x][i] = 2 +(2*x);
		}
	}
}
int multiply_array(int anarray[2][5])
{

	change_array(anarray);
	print_array(anarray);

	int x;
	for (int i = 0; i < 2; i++)
	{
		x = i;
		for (int i = 0; i < 5; i++)
		{
			anarray[x][i] = anarray[x][i] * 2;
		}
	}

	print_array(anarray);
}