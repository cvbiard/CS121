#include <stdio.h>

//int main(void) 
//{
	////Problem 1
	//int matrix[10][5];
	//int x = 0, y = 0;

	//for (x = 0; x < 10; x++)
	//{
	//	for (y = 0; y < 5; y++)
	//	{
	//		matrix[x][y] = x - y;
	//	}
	//}

	//printf("Matrix elements are: ");
	//for (x = 0; x < 10; x++)
	//{
	//	for (y = 0; y < 5; y++)
	//	{
	//		printf("%d ", matrix[x][y]);
	//	}
	/*}*/

	//return 0;

//Function to return minimum of matrix
	int find_min(int array[][10], int c, int r)
	{
		int i, j;
		int x = 0, y = 0;
		int min = 2147483647;

		for (x = 0; x < c; x++)
		{
			for (y = 0; y < r; y++)
			{
				if (min > array[x][y])
				{
					min = array[x][y];
				}
			}

		return min;
	}

		int main(void)
	{
		//declaraing variable
		int mat[10][10];
		int r, c;
		int i, j;

		//taking input of row and column from user
		printf("Enter Row Size : ");
		scanf("%d", &r);
		printf("\nEnter Column Size : ");
		scanf("%d", &c);

		//taking matrix from the user
		printf("\nEnter Matrix Below :- \n\n");
		for (i = 0; i < r; i++)
			for (j = 0; j < c; j++)
				scanf("%d", &mat[i][j]);

		//printing and calling find_min
		printf("\nMin : %d", find_min(mat, r, c));

		return 0;
	}
