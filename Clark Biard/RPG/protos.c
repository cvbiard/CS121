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
int col_check(char array[width][height], char functional[width][height], int pos[2], char input)
{
	if (input == 'w')
	{
		if (functional[pos[1]][pos[0] - 1] != 'c')
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if (input == 's')
	{
		
		if (functional[pos[1]][pos[0] + 1] != 'c')
		{
				return 1;
		}
		else
		{
			return 0;
		}
		
	}
	if (input == 'a')
	{
		
		if (functional[pos[1] - 1][pos[0]] != 'c')
		{
				return 1;
		}
		else
		{
			return 0;
		}
		
	}
	if (input == 'd')
	{
		if (functional[pos[1] + 1][pos[0]] != 'c')
		{
				return 1;
		}
		else
		{
			return 0;
		}
	}
}
void update_location(char array[width][height], char ref[width][height], char functional[width][height], int pos[2], char input)
{
	array[pos[1]][pos[0]] = ref[pos[1]][pos[0]];
	if (input == 'w')
	{
		if (pos[0] - 1 >= 0 && pos[0] - 1 <= height - 1)
		{
			
		pos[0] = pos[0] - col_check(array, functional, pos, input);
			
		}
	}
	if (input == 's')
	{
		if (pos[0] + 1 >= 0 && pos[0] + 1 <= height - 1)
		{
			
		pos[0] = pos[0] + col_check(array, functional, pos, input);
			
		}
	}
	if (input == 'a')
	{
		if (pos[1] - 1 >= 0 && pos[1] - 1 <= width - 1)
		{
			
		pos[1] = pos[1] - col_check(array, functional, pos, input);
			
		}
	}
	if (input == 'd')
	{
		if (pos[1] + 1 >= 0 && pos[1] + 1 <= width - 1)
		{
			
		pos[1] = pos[1] + col_check(array, functional, pos, input);
			
		}
	}
	
	
	array[pos[1]][pos[0]] = 'o';
}
void load_scene(struct asset scene, char array[width][height], char ref[width][height], char functional[width][height])
{
	if (scene.visual_asset == NULL)
	{
		printf("File not opened");
	}
	if (scene.functional_asset == NULL)
	{
		printf("File not opened");
	}
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			fscanf(scene.visual_asset, "%c", &array[j][i]);
		}
		fscanf(scene.visual_asset, "%*c");
	}
	rewind(scene.visual_asset);

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			fscanf(scene.visual_asset, "%c", &ref[j][i]);
		}
		fscanf(scene.visual_asset, "%*c");
	}

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			fscanf(scene.functional_asset, "%c", &functional[j][i]);
		}
		fscanf(scene.functional_asset, "%*c");
	}
}
void print_menu(char text[])
{
	/*for (int i = 0; i <= height / 3; i++)
	{
		if (i == 0)
		{
			printf("_");
		}
		else
		{
			printf("|");
		}
		for (int j = 0; j <= width; j++)
		{
			if (i > 0 && i < height/3)
			{
				if (text[j] >= 0 && text[j] <= 127)
				{
					printf("%c", text[j]);
				}
				else if (j > 0 && j < width)
				{
					printf("_");
				}
				else
				{
					printf("_|");
				}
			}
			else
			{
				printf("_");
			}
		}
		
		
		printf("\n");
	}*/
	int textdone = 0, textcounter = 0;
	printf(" ");
	for (int i = 0; i < width; i++)
	{
		if (i == 0 || i == width - 1)
		{
			printf(" ");
		}
		else
		{
			printf("_");
		}
	}
	printf("\n");

	for (int l = 0; l < height / 3; l++)
	{
		printf(" ");
		for (int j = 0; j <= width - 1; j++)
		{
			if (j == 0 || j == width - 1)
			{
				printf("|");
			}
			else
			{
				if (text[textcounter] > 0 && text[textcounter] <= 127)
				{
					if (textdone == 0)
					{
						printf("%c", text[textcounter]);
						textcounter = textcounter + 1;
					}
					else
					{
						printf(" ");
					}
				}
				else
				{
					printf(" ");
					textdone = 1;
				}
			}
		}
		printf("\n");
	}

	printf(" ");
	for (int i = 0; i < width; i++)
	{
		if (i == 0 || i == width -1)
		{
			printf("|");
		}
		else
		{
			printf("_");
		}
	}
	printf("\n");
}