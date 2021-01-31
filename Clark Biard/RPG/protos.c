#include "header.h"

void load_settings(FILE* settings)
{
	char debug_state = '\0';
	if (settings != NULL)
	{
		fscanf(settings, "%*c%*c%*c%*c%*c%*c%*c%c", &debug_state);
		if (debug_state == 't' || debug_state == 'T')
		{
			printf("Debug set to true.\n");
			debug_state = 't';
		}
		else if (debug_state == 'f' || debug_state == 'F')
		{
			printf("Debug set to false.\n");
			debug_state = 'f';
		}
		printf("Debug macro is %c.\n", debug);
	}
}

void init_screen(char array[width][height])
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			array[j][i] = '-';
		}
	}
}
void print_screen(char array[width][height], int pos[2])
{
	char current = '\0';
	array[pos[1]][pos[0]] = 'o';
	for (int j = 0; j < width; j++)
	{
		printf("#");
	}
	printf("##\n");

	for (int i = 0; i < height; i++)
	{
		printf("#");
		for (int j = 0; j < width; j++)
		{
			current = array[j][i];
			if (current == 'x')
			{
				printf(" ");
			}
			else
			{
				printf("%c", current);
			}
		}
		printf("#");
		printf("\n");
	}
	for (int j = 0; j < width; j++)
	{
		printf("#");
	}
	printf("##\n");
}
char update_location(char array[width][height], int pos[2], char input, char prev)
{
	array[pos[1]][pos[0]] = prev;
	if (input == 'w')
	{
		if (pos[0] - 1 >= 0 && pos[0] - 1 <= height - 1)
		{
			prev = array[pos[1]][pos[0]-1];
			pos[0] = pos[0] - 1;
		}
	}
	if (input == 's')
	{
		if (pos[0] + 1 >= 0 && pos[0] + 1 <= height - 1)
		{
			prev = array[pos[1]][pos[0]+1];
			pos[0] = pos[0] + 1;
		}
	}
	if (input == 'a')
	{
		if (pos[1] - 1 >= 0 && pos[1] - 1 <= width - 1)
		{
			prev = array[pos[1]-1][pos[0]];
			pos[1] = pos[1] - 1;
		}
	}
	if (input == 'd')
	{
		if (pos[1] + 1 >= 0 && pos[1] + 1 <= width - 1)
		{
			prev = array[pos[1]+1][pos[0]];
			pos[1] = pos[1] + 1;
		}
	}
	
	
	array[pos[1]][pos[0]] = 'o';
	return prev;
}
void load_scene(FILE* scene, char array[width][height])
{
	if (scene == NULL)
	{
		printf("File not opened");
	}
	{
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				fscanf(scene, "%c", &array[j][i]);
			}
			fscanf(scene, "%*c");
		}
	}
}