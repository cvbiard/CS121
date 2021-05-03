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
	int move_disk = 0;
	int move_tower = 0;


}