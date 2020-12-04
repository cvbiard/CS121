#include "Lab13.header.h"

void shift_four(int number)
{
	int x = 0, y = 0;
	for (y = 15; y >= 0; y--) 
	{
		x = number / (1 << y);
		number = number - x * (1 << y);
		printf("%d", x);
	}
	printf("\n");
}