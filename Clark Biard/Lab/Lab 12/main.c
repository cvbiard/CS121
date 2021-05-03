#include "header.h"

int main(void)
{
	
	char mazearr[8][8] = 
	{'O', 'O', 'X','X', 'X', 'X', 'X', 'X',
	 'X', 'O', 'O','X', 'X', 'X', 'X', 'X', 
	 'X', 'X', 'O','O', 'X', 'X', 'X', 'X', 
	 'X', 'X', 'X','O', 'X', 'X', 'X', 'X', 
	 'X', 'X', 'X','O', 'O', 'O', 'O', 'X', 
	 'X', 'X', 'X','X', 'X', 'X', 'O', 'X', 
	 'X', 'X', 'X','X', 'X', 'X', 'O', 'X', 
	 'X', 'X', 'X','X', 'X', 'X', 'X', 'O'};

	int pos[2] = { 0, 0 };
	int results = 0;
	char test[] = "test";

	Post post1;
	post1.disk1 = 1;
	post1.disk2 = 1;
	post1.disk3 = 1;

	Post post2;
	post2.disk1 = 0;
	post2.disk2 = 0;
	post2.disk3 = 0;

	Post post3;
	post3.disk1 = 0;
	post3.disk2 = 0;
	post3.disk3 = 0;

	Post Tower[3] = { post1, post2, post3 };

	//results = maze(mazearr, pos);

	/*if (results == 0)
	{
		printf("There is no path.\n");
	}*/

	//results = sum_digits(123);
	//printf("%d", results);
	/*printf("%s\n", test);
	reverse_string(test, 0, 3);
	printf("%s\n", test);*/
	return 0;
}