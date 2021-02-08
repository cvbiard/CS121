#include "header.h"


int main(void)
{

	FILE* settings = fopen("settings.txt", "r");
	char screen[width*6][height*3], functional[width][height], input = '\0';
	char TestText[] = "This is test text, and I'm making it long to see what happens :)";
	int tile_ids[width][height], ref[width][height];
	

	int exit = 0;

	struct object player;
	player.xpos = 0;
	player.ypos = 0;
	
	struct asset TestZone;
	TestZone.visual_asset = fopen("TileTestZone.txt", "r");
	TestZone.functional_asset = fopen("TileTestZone.txt", "r");
	
	char TestTileArr[6][3] = { '\0' };

	struct tile Player;
	Player.id = 0;
	Player.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Player.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Player.asset = fopen("PlayerTile.txt", "r");

	struct tile TestTile;
	TestTile.id = 1;
	TestTile.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		TestTile.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	TestTile.asset = fopen("TestTile.txt", "r");

	struct tile TestTile2;
	TestTile2.id = 2;
	TestTile2.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		TestTile2.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	TestTile2.asset = fopen("TestTile2.txt", "r");

	struct tile tiles[3] = {Player, TestTile, TestTile2 };

	int pos[2] = { player.xpos, player.ypos };

	init_screen(screen);
	init_tile(TestTile);
	load_tile(TestTile);
	init_tile(TestTile2);
	load_tile(TestTile2);
	init_tile(Player);
	load_tile(Player);
	load_scene(TestZone, screen, tile_ids, ref, tiles);
	print_screen(screen, pos, tiles, tile_ids);
	print_menu(TestText);
	load_settings(settings);


	while (exit != 1)
	{
		input = _getche();

		update_location(tile_ids, ref, pos, input);
		input = '\0';
		system("cls");
		print_screen(screen, pos, tiles, tile_ids);
		print_menu(TestText);
		printf("Player position is %d %d.\n", pos[0], pos[1]);
	}

	return 0;
}