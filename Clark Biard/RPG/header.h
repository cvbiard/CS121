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
	char flags[2];
};

void load_settings(FILE* settings);
void init_screen(char array[60][30]);
void print_screen(char array[60][30], int pos[2], struct tile tiles[3], int tile_ids[width][height]);
int col_check(char array[60][30], int ref[width][height], int pos[2], char input, struct tile tiles[4]);
void update_location(int array[width][height], int ref[width][height], int pos[2], char input, struct tile tiles[4]);
void load_scene(struct asset scene, char array[60][30], int tile_ids[width][height], int ref[width][height], struct tile tiles[2]);
void load_tile(struct tile tile);
void print_menu(char text[]);
void init_tile(struct tile tile);
void print_tile(struct tile tile);
void print_tile_ids(int tile_ids[width][height]);
//void tile_frequency(int tile_ids[width][height])
//Next thing we need to do is set up a way to have only the needed tiles loaded for a scene.
//I think we do this by each tile having a local ID and global ID, local being it's ID in a scene (0 - 100 since max unique tiles is 100, or 10X10)
//And global is relative to all tiles, basically tieing a number to the file name to be opened into the local ID spot when the scene is opened.