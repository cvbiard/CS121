#include "header.h"

void main(void)
{
	FILE* input = fopen("in.txt", "r");
	int arr[1] = { 0 };
	int arr2[20];
	int ft[101];
	int man_counter = 0;

	char word[5] = { 'h', 'o', 'u', 's', 'e' };

	srand(time(0));

	/*read_to_array(arr, input);
	printf("Made it out the func baby\n");*/

	populate_array(arr2);
	print_arr(arr2, 20);
	frequency(arr2, ft);
	print_arr(ft, 101);

	

}