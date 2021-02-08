#define _CRT_SECURE_NO_WARNINGS

#define height 10
#define width height
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
struct tile
{
	int id;
	char** layout;
	FILE* asset;
};

void load_settings(FILE* settings);
void init_screen(char array[60][30]);
void print_screen(char array[60][30], int pos[2], struct tile tiles[3], int tile_ids[width][height]);
int col_check(char array[60][30], char functional[width][height], int pos[2], char input);
void update_location(int array[width][height], int ref[width][height], int pos[2], char input);
void load_scene(struct asset scene, char array[60][30], int tile_ids[width][height], int ref[width][height], struct tile tiles[2]);
void load_tile(struct tile tile);
void print_menu(char text[]);
void init_tile(struct tile tile);
void print_tile(struct tile tile);
void print_tile_ids(int tile_ids[width][height]);