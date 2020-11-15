#include "header.h"

int main()
{
	int anarray[2][5] = { { 0, 1, 2, 3, 4 }, { 4, 3, 2, 1, 0 } };
	
	print_array(anarray);
	multiply_array(anarray);
	return 0;
}