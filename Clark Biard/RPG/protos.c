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

void init_screen(char array[60][30])
{
	for (int i = 0; i < height*3; i++)
	{
		for (int j = 0; j < width*6; j++)
		{
			array[j][i] = '-';
		}
	}
}
void print_screen(char array[60][30], int pos[2], struct tile tiles[3], int tile_ids[width][height])
{

	for (int i = 0; i < height * 3; i = i + 3)
	{
		for (int j = 0; j < width * 6; j = j + 6)
		{
			for (int k = 0; k < 6; k++)
			{
				for (int l = 0; l < 3; l++)
				{
					array[k + j][i + l] = tiles[tile_ids[j / 6][i / 3]].layout[k][l];
				}
			}
		}
	}
	printf(" ");
	for (int i = 0; i < width*6; i++)
	{
		printf("#");
	}
	printf("\n");
	for (int i = 0; i < height*3; i++)
	{
		printf("#");
		for (int j = 0; j < width*6; j++)
		{
			if (array[j][i] == 'x')
			{
				printf(" ");
			}
			else
			{
				printf("%c", array[j][i]);
			}

		}
		printf("#");
		printf("\n");
	}
	printf(" ");
	for (int i = 0; i < width * 6; i++)
	{
		printf("#");
	}
	printf("\n");
}
int col_check(char array[60][30], char functional[width][height], int pos[2], char input)
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
	return 0;
}
void update_location(int array[width][height], int ref[width][height], int pos[2], char input)
{
	array[pos[1]][pos[0]] = ref[pos[1]][pos[0]];
	if (input == 'w')
	{
		if (pos[0] - 1 >= 0 && pos[0] - 1 <= height - 1)
		{
			
		pos[0] = pos[0] - 1;
			
		}
	}
	if (input == 's')
	{
		if (pos[0] + 1 >= 0 && pos[0] + 1 <= height - 1)
		{
			
		pos[0] = pos[0] + 1;
			
		}
	}
	if (input == 'a')
	{
		if (pos[1] - 1 >= 0 && pos[1] - 1 <= width - 1)
		{
			
		pos[1] = pos[1] - 1;
			
		}
	}
	if (input == 'd')
	{
		if (pos[1] + 1 >= 0 && pos[1] + 1 <= width - 1)
		{
			
		pos[1] = pos[1] + 1;
			
		}
	}
	
	
	array[pos[1]][pos[0]] = 0;
}
void load_scene(struct asset scene, char array[60][30], int tile_ids[width][height], int ref[width][height], struct tile tiles[2])
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			fscanf(scene.visual_asset, "%d", &tile_ids[j][i]);
			ref[j][i] = tile_ids[j][i];
		}
	}
	rewind(scene.visual_asset);
	//print_tile_ids(tile_ids);

	/*for (int i = 0; i < height * 3; i = i + 3)
	{
		for (int j = 0; j < width * 6; j = j + 6)
		{
			for (int k = 0; k < 6; k++)
			{
				for (int l = 0; l < 3; l++)
				{
					array[k + j][i + l] = tiles[tile_ids[j/6][i/3]].layout[k][l];
				}
			}
		}
	}*/

	//for (int i = 0; i < height; i++)
	//{
	//	for (int j = 0; j < width; j++)
	//	{
	//		fscanf(scene.visual_asset, "%d", &ref[j][i]);
	//	}
	//	fscanf(scene.visual_asset, "%*c");
	//}
	//rewind(scene.visual_asset);

	//for (int i = 0; i < height; i++)
	//{
	//	for (int j = 0; j < width; j++)
	//	{
	//		fscanf(scene.functional_asset, "%d", &functional[j][i]);
	//	}
	//	fscanf(scene.functional_asset, "%*c");
	//}
	//rewind(scene.functional_asset);
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
	for (int i = 0; i < width*6; i++)
	{
		if (i == 0 || i == width*6 - 1)
		{
			printf(" ");
		}
		else
		{
			printf("_");
		}
	}
	printf("\n");

	for (int l = 0; l < height*3 / 3; l++)
	{
		printf(" ");
		for (int j = 0; j <= width*6 - 1; j++)
		{
			if (j == 0 || j == width*6 - 1)
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
	for (int i = 0; i < width*6; i++)
	{
		if (i == 0 || i == width*6 -1)
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
void load_tile(struct tile tile)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			fscanf(tile.asset, "%c", &tile.layout[j][i]);
		}
		fscanf(tile.asset, "%*c");
	}
	rewind(tile.asset);
}
void init_tile(struct tile tile)
{
	int vind, hind;
	for (int i = 0; i < 3; i++)
	{
		vind = i;
		for (int i = 0; i < 6; i++)
		{
			hind = i;
			tile.layout[vind][hind] = '~';
		}
	}

}
void print_tile(struct tile tile)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			printf("%c", tile.layout[j][i]);
		}
		printf("\n");
	}
}
void print_tile_ids(int tile_ids[width][height])
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			printf("%d", tile_ids[j][i]);
		}
		printf("\n");
	}
}