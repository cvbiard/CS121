#define _CRT_SECURE_NO_WARNINGS

#define height 15
#define width 2*height
#define debug debug_state

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct object
{
	int xpos;
	int ypos;
};
struct asset
{
	FILE* visual_asset;
	FILE* functional_asset;
};

void load_settings(FILE* settings);
void init_screen(char array[width][height]);
void print_screen(char array[width][height], int pos[2]);
int col_check(char array[width][height], char functional[width][height], int pos[2], char input);
void update_location(char array[width][height], char ref[width][height], char functional[width][height], int pos[2], char input);
void load_scene(struct asset scene, char array[width][height], char ref[width][height], char functional[width][height]);
void print_menu(char text[]);