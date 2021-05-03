#include "header.h"

int maze(char mazearr[8][8], int pos[2])
{
	int result = 0;
	if (pos[0] == 7 && pos[1] == 7)
	{
		return 1;
	}

	if (pos[0] + 1 <= 7 && pos[0] + 1 >= 0)
	{
		printf("Looking at %d %d.\n", pos[0], pos[1]);
		if (mazearr[pos[0] + 1][pos[1]] == 'O')
		{
			mazearr[pos[0]][pos[1]] = '0';
			pos[0] = pos[0] + 1;
			result = maze(mazearr, pos);
			if (result == 1)
			{
				pos[0] = pos[0] - 1;
				printf("Pos %d %d is part of the path.\n", pos[0], pos[1]);
				return 1;
			}
			else
			{
				mazearr[pos[0]][pos[1]] = 'O';
				pos[0] = pos[0] - 1;
			}
		}
	}
	
	if (pos[1] + 1 <= 7 && pos[1] + 1 >= 0)
	{
		printf("Looking at %d %d.\n", pos[0], pos[1]);
		if (mazearr[pos[0]][pos[1] + 1] == 'O')
		{
			mazearr[pos[0]][pos[1]] = '0';
			pos[1] = pos[1] + 1;
			result = maze(mazearr, pos);
			if (result == 1)
			{
				
				pos[1] = pos[1] - 1;
				printf("Pos %d %d is part of the path.\n", pos[0], pos[1]);
				return 1;
			}
			else
			{
				mazearr[pos[0]][pos[1]] = 'O';
				pos[1] = pos[1] - 1;
				
			}
			
		}
	}
	
	if (pos[0] - 1 <= 7 && pos[0] - 1 >= 0)
	{
		printf("Looking at %d %d.\n", pos[0], pos[1]);
		if (mazearr[pos[0] - 1][pos[1]] == 'O')
		{
			mazearr[pos[0]][pos[1]] = '0';
			pos[0] = pos[0] - 1;
			result = maze(mazearr, pos);
			if (result == 1)
			{
				
				pos[0] = pos[0] + 1;
				printf("Pos %d %d is part of the path.\n", pos[0], pos[1]);
				return 1;
			}
			else
			{
				mazearr[pos[0]][pos[1]] = 'O';
				pos[0] = pos[0] + 1;
			}
		}
	}
	
	if (pos[1] - 1 <= 7 && pos[1] - 1 >= 0)
	{
		//printf("Looking at %d %d.\n", pos[0], pos[1]);
		if (mazearr[pos[0]][pos[1] - 1] == 'O')
		{
			mazearr[pos[0]][pos[1]] = '0';
			pos[1] = pos[1] - 1;
			result = maze(mazearr, pos);
			if (result == 1)
			{
			
				pos[1] = pos[1] + 1;
				printf("Pos %d %d is part of the path.\n", pos[0], pos[1]);
				return 1;
			}
			else
			{
				mazearr[pos[0]][pos[1]] = 'O';
				pos[1] = pos[1] + 1;
				
			}
			
		}
	}
	
	return 0;
	
}
int sum_digits(int number)
{
	int current = 0;

	if (number == 0)
	{
		return 0;
		
	}
	
	return (number%10 + sum_digits(number/10));

}
void reverse_string(char* string, int start, int end)
{
	char temp;

	if (start >= end)
	{
		return;
	}

	temp = *(string + start);
	*(string + start) = *(string + end);
	*(string + end) = temp;

	reverse_string(string, (start+1), (end-1));
}
int tower_game(Post tower[3])
{
	int disk_from = 0, disk_to = 0;

	int end = 0;

	while (end != 1)
	{
		if (tower[0].total > 0)
		{
			printf("Tower Zero currently has disk(s)");
			if (tower[0].disk[0] == 1)
			{
				printf(" 1");
			}
			if (tower[0].disk[1] == 1)
			{
				printf(" 2");
			}
			if (tower[0].disk[2] == 1)
			{
				printf(" 3");
			}
			printf("\n");
		}
		if (tower[1].total > 0)
		{
			printf("Tower One currently has disk(s)");
			if (tower[1].disk[0] == 1)
			{
				printf(" 1");
			}
			if (tower[1].disk[1] == 1)
			{
				printf(" 2");
			}
			if (tower[1].disk[2] == 1)
			{
				printf(" 3");
			}
			printf("\n");
		}
		if (tower[2].total > 0)
		{
			printf("Tower Two currently has disk(s)");
			if (tower[2].disk[0] == 1)
			{
				printf(" 1");
			}
			if (tower[2].disk[1] == 1)
			{
				printf(" 2");
			}
			if (tower[2].disk[2] == 1)
			{
				printf(" 3");
			}
			printf("\n");
		}

		int range = 0;
		printf("Which tower would you like to move the top disc from?\n");
		scanf("%d", &disk_from);
		
		
		
			while (range != 1)
			{
				if (disk_from > 2 || disk_from < 0)
				{
					printf("Please enter a number from 0 to 2.\n");
					scanf("%d", &disk_from);
				}
				else
				{
					range = 1;
				}
			}
		
			range = 0;
		


		int check = 0;
		for (int i = 0; i < 3; i++)
		{
			if (tower[disk_from].disk[i] > 0)
			{
				printf("Which tower would you like to move this disc to?\n");
				scanf("%d", &disk_to);

				while (range != 1)
				{
					if (disk_to > 2 || disk_to < 0)
					{
						printf("Please enter a number from 0 to 2.\n");
						scanf("%d", &disk_to);
					}
					else
					{
						range = 1;
					}
				}
				
				while (check != 1)
				{
					if (i - 1 >= 0 && i - 1 <= 2 && tower[disk_to].disk[i - 1] > 0 )
					{
						printf("There is a smaller disc on this tower already, please enter another tower.\n");
						scanf("%d", &disk_to);
					}
					else
					{
						check = 1;
					}
				}

				tower[disk_from].disk[i] = 0;
				tower[disk_from].total = tower[disk_from].total - 1;
				tower[disk_to].disk[i] = 1;
				tower[disk_to].total = tower[disk_to].total + 1;
				break;
			}
		}
		end = check_win(tower, 0);
	}
	
	printf("You won.");
 	return 0;

}
int check_win(Post tower[3], int count)
{
	int check = 0;
	int number = 0;
	if (count < 3)
	{
		if (tower[count].total == 3)
		{
			return 1;
		}
		else
		{
			check = check_win(tower, count + 1);
		}
	}
	if (check > 0)
	{
		return 1;
	}
	return 0;
}