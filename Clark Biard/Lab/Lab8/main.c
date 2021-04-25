#include "header.h"

int main(void)
{
	FILE* input = fopen("in.txt", "r");
	int arr[5] = { 0, 0, 0, 0, 0 };

	read_to_array(arr, input);

	return 0;
}