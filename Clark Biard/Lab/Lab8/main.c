#include "header.h"

void main(void)
{
	FILE* input = fopen("in.txt", "r");
	int arr[1] = { 0 };

	read_to_array(arr, input);
	printf("Made it out the func baby\n");

}