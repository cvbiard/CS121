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
	FILE* asset;
};

void load_settings(FILE* settings);
void init_screen(char array[width][height]);
void print_screen(char array[width][height], int pos[2]);
char update_location(char array[width][height], int pos[2], char input, char prev);
void load_scene(FILE* scene, char array[width][height]);