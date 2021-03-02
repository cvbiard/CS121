#include "header.h"


int main(void)
{

	FILE* settings = fopen("settings.txt", "r");
	char screen[width*6][height*3], functional[width][height], input = '\0';
	char TestText[] = "This is test text, and I'm making it long to see what happens :)";
	int tile_ids[width][height], ref[width][height], tile_frequency[100] = { 0 };
	
	struct tile Dummy;
	Dummy.id = 0;
	Dummy.file[0] = "Dummy.txt";
	strcpy(Dummy.file, "Dummy.txt");
	Dummy.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Dummy.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Dummy.asset = fopen("Dummy.txt", "r");
	Dummy.flags[0] = '\0';
	Dummy.flags[1] = '\0';

	init_tile(Dummy);
	load_tile(Dummy);

	struct tile Player_global;
	Player_global.id = 1;
	Player_global.file[0] = "PlayerTile.txt";
	strcpy(Player_global.file, "PlayerTile.txt");

	struct tile TestTile_global;
	TestTile_global.id = 2;
	TestTile_global.file[0] = "TestTile.txt";
	strcpy(TestTile_global.file, "TestTile.txt");

	struct tile TestTile2_global;
	TestTile2_global.id = 3;
	TestTile2_global.file[0] = "TestTile2.txt";
	strcpy(TestTile2_global.file, "TestTile2.txt");

	struct tile Door_global;
	Door_global.id = 4;
	Door_global.file[0] = "TestDoor.txt";
	strcpy(Door_global.file, "TestDoor.txt");

	struct tile Tiles[100] = {Dummy, Player_global, TestTile_global, TestTile2_global, Door_global};
	

	int exit = 0;

	struct object player;
	player.xpos = 0;
	player.ypos = 0;
	
	struct asset TestZone;
	TestZone.visual_asset = fopen("TileTestZone.txt", "r");
	TestZone.functional_asset = fopen("TileTestZone.txt", "r");
	
	char TestTileArr[6][3] = { '\0' };

	struct tile Tile0;
	Tile0.id = Dummy.id;
	Tile0.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile0.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile0.flags[0] = '\0';
	Tile0.flags[1] = '\0';
	Tile0.asset = Dummy.asset;
	
	struct tile Tile1;
	Tile1.id = Dummy.id;
	Tile1.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile1.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile1.flags[0] = '\0';
	Tile1.flags[1] = '\0';
	Tile1.asset = Dummy.asset;
	
	struct tile Tile2;
	Tile2.id = Dummy.id;
	Tile2.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile2.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile2.flags[0] = '\0';
	Tile2.flags[1] = '\0';
	Tile2.asset = Dummy.asset;
	
	struct tile Tile3;
	Tile3.id = Dummy.id;
	Tile3.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile3.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile3.flags[0] = '\0';
	Tile3.flags[1] = '\0';
	Tile3.asset = Dummy.asset;
	
	struct tile Tile4;
	Tile4.id = Dummy.id;
	Tile4.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile4.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile4.flags[0] = '\0';
	Tile4.flags[1] = '\0';
	Tile4.asset = Dummy.asset;
	
	struct tile Tile5;
	Tile5.id = Dummy.id;
	Tile5.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile5.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile5.flags[0] = '\0';
	Tile5.flags[1] = '\0';
	Tile5.asset = Dummy.asset;
	
	struct tile Tile6;
	Tile6.id = Dummy.id;
	Tile6.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile6.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile6.flags[0] = '\0';
	Tile6.flags[1] = '\0';
	Tile6.asset = Dummy.asset;
	
	struct tile Tile7;
	Tile7.id = Dummy.id;
	Tile7.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile7.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile7.flags[0] = '\0';
	Tile7.flags[1] = '\0';
	Tile7.asset = Dummy.asset;
	
	struct tile Tile8;
	Tile8.id = Dummy.id;
	Tile8.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile8.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile8.flags[0] = '\0';
	Tile8.flags[1] = '\0';
	Tile8.asset = Dummy.asset;
	
	struct tile Tile9;
	Tile9.id = Dummy.id;
	Tile9.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile9.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile9.flags[0] = '\0';
	Tile9.flags[1] = '\0';
	Tile9.asset = Dummy.asset;
	
	struct tile Tile10;
	Tile10.id = Dummy.id;
	Tile10.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile10.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile10.flags[0] = '\0';
	Tile10.flags[1] = '\0';
	Tile10.asset = Dummy.asset;
	
	struct tile Tile11;
	Tile11.id = Dummy.id;
	Tile11.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile11.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile11.flags[0] = '\0';
	Tile11.flags[1] = '\0';
	Tile11.asset = Dummy.asset;
	
	struct tile Tile12;
	Tile12.id = Dummy.id;
	Tile12.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile12.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile12.flags[0] = '\0';
	Tile12.flags[1] = '\0';
	Tile12.asset = Dummy.asset;
	
	struct tile Tile13;
	Tile13.id = Dummy.id;
	Tile13.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile13.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile13.flags[0] = '\0';
	Tile13.flags[1] = '\0';
	Tile13.asset = Dummy.asset;
	
	struct tile Tile14;
	Tile14.id = Dummy.id;
	Tile14.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile14.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile14.flags[0] = '\0';
	Tile14.flags[1] = '\0';
	Tile14.asset = Dummy.asset;
	
	struct tile Tile15;
	Tile15.id = Dummy.id;
	Tile15.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile15.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile15.flags[0] = '\0';
	Tile15.flags[1] = '\0';
	Tile15.asset = Dummy.asset;
	
	struct tile Tile16;
	Tile16.id = Dummy.id;
	Tile16.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile16.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile16.flags[0] = '\0';
	Tile16.flags[1] = '\0';
	Tile16.asset = Dummy.asset;
	
	struct tile Tile17;
	Tile17.id = Dummy.id;
	Tile17.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile17.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile17.flags[0] = '\0';
	Tile17.flags[1] = '\0';
	Tile17.asset = Dummy.asset;
	
	struct tile Tile18;
	Tile18.id = Dummy.id;
	Tile18.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile18.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile18.flags[0] = '\0';
	Tile18.flags[1] = '\0';
	Tile18.asset = Dummy.asset;
	
	struct tile Tile19;
	Tile19.id = Dummy.id;
	Tile19.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile19.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile19.flags[0] = '\0';
	Tile19.flags[1] = '\0';
	Tile19.asset = Dummy.asset;
	
	struct tile Tile20;
	Tile20.id = Dummy.id;
	Tile20.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile20.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile20.flags[0] = '\0';
	Tile20.flags[1] = '\0';
	Tile20.asset = Dummy.asset;
	
	struct tile Tile21;
	Tile21.id = Dummy.id;
	Tile21.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile21.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile21.flags[0] = '\0';
	Tile21.flags[1] = '\0';
	Tile21.asset = Dummy.asset;
	
	struct tile Tile22;
	Tile22.id = Dummy.id;
	Tile22.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile22.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile22.flags[0] = '\0';
	Tile22.flags[1] = '\0';
	Tile22.asset = Dummy.asset;
	
	struct tile Tile23;
	Tile23.id = Dummy.id;
	Tile23.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile23.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile23.flags[0] = '\0';
	Tile23.flags[1] = '\0';
	Tile23.asset = Dummy.asset;
	
	struct tile Tile24;
	Tile24.id = Dummy.id;
	Tile24.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile24.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile24.flags[0] = '\0';
	Tile24.flags[1] = '\0';
	Tile24.asset = Dummy.asset;
	
	struct tile Tile25;
	Tile25.id = Dummy.id;
	Tile25.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile25.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile25.flags[0] = '\0';
	Tile25.flags[1] = '\0';
	Tile25.asset = Dummy.asset;
	
	struct tile Tile26;
	Tile26.id = Dummy.id;
	Tile26.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile26.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile26.flags[0] = '\0';
	Tile26.flags[1] = '\0';
	Tile26.asset = Dummy.asset;
	
	struct tile Tile27;
	Tile27.id = Dummy.id;
	Tile27.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile27.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile27.flags[0] = '\0';
	Tile27.flags[1] = '\0';
	Tile27.asset = Dummy.asset;
	
	struct tile Tile28;
	Tile28.id = Dummy.id;
	Tile28.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile28.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile28.flags[0] = '\0';
	Tile28.flags[1] = '\0';
	Tile28.asset = Dummy.asset;
	
	struct tile Tile29;
	Tile29.id = Dummy.id;
	Tile29.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile29.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile29.flags[0] = '\0';
	Tile29.flags[1] = '\0';
	Tile29.asset = Dummy.asset;
	
	struct tile Tile30;
	Tile30.id = Dummy.id;
	Tile30.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile30.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile30.flags[0] = '\0';
	Tile30.flags[1] = '\0';
	Tile30.asset = Dummy.asset;
	
	struct tile Tile31;
	Tile31.id = Dummy.id;
	Tile31.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile31.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile31.flags[0] = '\0';
	Tile31.flags[1] = '\0';
	Tile31.asset = Dummy.asset;
	
	struct tile Tile32;
	Tile32.id = Dummy.id;
	Tile32.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile32.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile32.flags[0] = '\0';
	Tile32.flags[1] = '\0';
	Tile32.asset = Dummy.asset;
	
	struct tile Tile33;
	Tile33.id = Dummy.id;
	Tile33.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile33.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile33.flags[0] = '\0';
	Tile33.flags[1] = '\0';
	Tile33.asset = Dummy.asset;
	
	struct tile Tile34;
	Tile34.id = Dummy.id;
	Tile34.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile34.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile34.flags[0] = '\0';
	Tile34.flags[1] = '\0';
	Tile34.asset = Dummy.asset;
	
	struct tile Tile35;
	Tile35.id = Dummy.id;
	Tile35.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile35.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile35.flags[0] = '\0';
	Tile35.flags[1] = '\0';
	Tile35.asset = Dummy.asset;
	
	struct tile Tile36;
	Tile36.id = Dummy.id;
	Tile36.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile36.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile36.flags[0] = '\0';
	Tile36.flags[1] = '\0';
	Tile36.asset = Dummy.asset;
	
	struct tile Tile37;
	Tile37.id = Dummy.id;
	Tile37.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile37.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile37.flags[0] = '\0';
	Tile37.flags[1] = '\0';
	Tile37.asset = Dummy.asset;
	
	struct tile Tile38;
	Tile38.id = Dummy.id;
	Tile38.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile38.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile38.flags[0] = '\0';
	Tile38.flags[1] = '\0';
	Tile38.asset = Dummy.asset;
	
	struct tile Tile39;
	Tile39.id = Dummy.id;
	Tile39.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile39.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile39.flags[0] = '\0';
	Tile39.flags[1] = '\0';
	Tile39.asset = Dummy.asset;
	
	struct tile Tile40;
	Tile40.id = Dummy.id;
	Tile40.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile40.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile40.flags[0] = '\0';
	Tile40.flags[1] = '\0';
	Tile40.asset = Dummy.asset;
	
	struct tile Tile41;
	Tile41.id = Dummy.id;
	Tile41.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile41.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile41.flags[0] = '\0';
	Tile41.flags[1] = '\0';
	Tile41.asset = Dummy.asset;
	
	struct tile Tile42;
	Tile42.id = Dummy.id;
	Tile42.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile42.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile42.flags[0] = '\0';
	Tile42.flags[1] = '\0';
	Tile42.asset = Dummy.asset;
	
	struct tile Tile43;
	Tile43.id = Dummy.id;
	Tile43.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile43.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile43.flags[0] = '\0';
	Tile43.flags[1] = '\0';
	Tile43.asset = Dummy.asset;
	
	struct tile Tile44;
	Tile44.id = Dummy.id;
	Tile44.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile44.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile44.flags[0] = '\0';
	Tile44.flags[1] = '\0';
	Tile44.asset = Dummy.asset;
	
	struct tile Tile45;
	Tile45.id = Dummy.id;
	Tile45.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile45.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile45.flags[0] = '\0';
	Tile45.flags[1] = '\0';
	Tile45.asset = Dummy.asset;

	struct tile Tile46;
	Tile46.id = Dummy.id;
	Tile46.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile46.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile46.flags[0] = '\0';
	Tile46.flags[1] = '\0';
	Tile46.asset = Dummy.asset;
	
	struct tile Tile47;
	Tile47.id = Dummy.id;
	Tile47.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile47.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile47.flags[0] = '\0';
	Tile47.flags[1] = '\0';
	Tile47.asset = Dummy.asset;
	
	struct tile Tile48;
	Tile48.id = Dummy.id;
	Tile48.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile48.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile48.flags[0] = '\0';
	Tile48.flags[1] = '\0';
	Tile48.asset = Dummy.asset;
	
	struct tile Tile49;
	Tile49.id = Dummy.id;
	Tile49.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile49.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile49.flags[0] = '\0';
	Tile49.flags[1] = '\0';
	Tile49.asset = Dummy.asset;
	
	struct tile Tile50;
	Tile50.id = Dummy.id;
	Tile50.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile50.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile50.flags[0] = '\0';
	Tile50.flags[1] = '\0';
	Tile50.asset = Dummy.asset;
	
	struct tile Tile51;
	Tile51.id = Dummy.id;
	Tile51.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile51.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile51.flags[0] = '\0';
	Tile51.flags[1] = '\0';
	Tile51.asset = Dummy.asset;
	
	struct tile Tile52;
	Tile52.id = Dummy.id;
	Tile52.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile52.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile52.flags[0] = '\0';
	Tile52.flags[1] = '\0';
	Tile52.asset = Dummy.asset;
	
	struct tile Tile53;
	Tile53.id = Dummy.id;
	Tile53.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile53.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile53.flags[0] = '\0';
	Tile53.flags[1] = '\0';
	Tile53.asset = Dummy.asset;
	
	struct tile Tile54;
	Tile54.id = Dummy.id;
	Tile54.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile54.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile54.flags[0] = '\0';
	Tile54.flags[1] = '\0';
	Tile54.asset = Dummy.asset;
	
	struct tile Tile55;
	Tile55.id = Dummy.id;
	Tile55.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile55.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile55.flags[0] = '\0';
	Tile55.flags[1] = '\0';
	Tile55.asset = Dummy.asset;
	
	struct tile Tile56;
	Tile56.id = Dummy.id;
	Tile56.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile56.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile56.flags[0] = '\0';
	Tile56.flags[1] = '\0';
	Tile56.asset = Dummy.asset;
	
	struct tile Tile57;
	Tile57.id = Dummy.id;
	Tile57.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile57.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile57.flags[0] = '\0';
	Tile57.flags[1] = '\0';
	Tile57.asset = Dummy.asset;
	
	struct tile Tile58;
	Tile58.id = Dummy.id;
	Tile58.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile58.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile58.flags[0] = '\0';
	Tile58.flags[1] = '\0';
	Tile58.asset = Dummy.asset;
	
	struct tile Tile59;
	Tile59.id = Dummy.id;
	Tile59.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile59.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile59.flags[0] = '\0';
	Tile59.flags[1] = '\0';
	Tile59.asset = Dummy.asset;
	
	struct tile Tile60;
	Tile60.id = Dummy.id;
	Tile60.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile60.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile60.flags[0] = '\0';
	Tile60.flags[1] = '\0';
	Tile60.asset = Dummy.asset;
	
	struct tile Tile61;
	Tile61.id = Dummy.id;
	Tile61.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile61.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile61.flags[0] = '\0';
	Tile61.flags[1] = '\0';
	Tile61.asset = Dummy.asset;
	
	struct tile Tile62;
	Tile62.id = Dummy.id;
	Tile62.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile62.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile62.flags[0] = '\0';
	Tile62.flags[1] = '\0';
	Tile62.asset = Dummy.asset;
	
	struct tile Tile63;
	Tile63.id = Dummy.id;
	Tile63.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile63.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile63.flags[0] = '\0';
	Tile63.flags[1] = '\0';
	Tile63.asset = Dummy.asset;
	
	struct tile Tile64;
	Tile64.id = Dummy.id;
	Tile64.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile64.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile64.flags[0] = '\0';
	Tile64.flags[1] = '\0';
	Tile64.asset = Dummy.asset;
	
	struct tile Tile65;
	Tile65.id = Dummy.id;
	Tile65.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile65.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile65.flags[0] = '\0';
	Tile65.flags[1] = '\0';
	Tile65.asset = Dummy.asset;
	
	struct tile Tile66;
	Tile66.id = Dummy.id;
	Tile66.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile66.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile66.flags[0] = '\0';
	Tile66.flags[1] = '\0';
	Tile66.asset = Dummy.asset;
	
	struct tile Tile67;
	Tile67.id = Dummy.id;
	Tile67.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile67.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile67.flags[0] = '\0';
	Tile67.flags[1] = '\0';
	Tile67.asset = Dummy.asset;
	
	struct tile Tile68;
	Tile68.id = Dummy.id;
	Tile68.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile68.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile68.flags[0] = '\0';
	Tile68.flags[1] = '\0';
	Tile68.asset = Dummy.asset;
	
	struct tile Tile69;
	Tile69.id = Dummy.id;
	Tile69.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile69.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile69.flags[0] = '\0';
	Tile69.flags[1] = '\0';
	Tile69.asset = Dummy.asset;
	
	struct tile Tile70;
	Tile70.id = Dummy.id;
	Tile70.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile70.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile70.flags[0] = '\0';
	Tile70.flags[1] = '\0';
	Tile70.asset = Dummy.asset;
	
	struct tile Tile71;
	Tile71.id = Dummy.id;
	Tile71.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile71.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile71.flags[0] = '\0';
	Tile71.flags[1] = '\0';
	Tile71.asset = Dummy.asset;
	
	struct tile Tile72;
	Tile72.id = Dummy.id;
	Tile72.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile72.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile72.flags[0] = '\0';
	Tile72.flags[1] = '\0';
	Tile72.asset = Dummy.asset;
	
	struct tile Tile73;
	Tile73.id = Dummy.id;
	Tile73.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile73.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile73.flags[0] = '\0';
	Tile73.flags[1] = '\0';
	Tile73.asset = Dummy.asset;
	
	struct tile Tile74;
	Tile74.id = Dummy.id;
	Tile74.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile74.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile74.flags[0] = '\0';
	Tile74.flags[1] = '\0';
	Tile74.asset = Dummy.asset;
	
	struct tile Tile75;
	Tile75.id = Dummy.id;
	Tile75.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile75.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile75.flags[0] = '\0';
	Tile75.flags[1] = '\0';
	Tile75.asset = Dummy.asset;
	
	struct tile Tile76;
	Tile76.id = Dummy.id;
	Tile76.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile76.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile76.flags[0] = '\0';
	Tile76.flags[1] = '\0';
	Tile76.asset = Dummy.asset;
	
	struct tile Tile77;
	Tile77.id = Dummy.id;
	Tile77.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile77.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile77.flags[0] = '\0';
	Tile77.flags[1] = '\0';
	Tile77.asset = Dummy.asset;
	
	struct tile Tile78;
	Tile78.id = Dummy.id;
	Tile78.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile78.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile78.flags[0] = '\0';
	Tile78.flags[1] = '\0';
	Tile78.asset = Dummy.asset;
	
	struct tile Tile79;
	Tile79.id = Dummy.id;
	Tile79.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile79.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile79.flags[0] = '\0';
	Tile79.flags[1] = '\0';
	Tile79.asset = Dummy.asset;
	
	struct tile Tile80;
	Tile80.id = Dummy.id;
	Tile80.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile80.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile80.flags[0] = '\0';
	Tile80.flags[1] = '\0';
	Tile80.asset = Dummy.asset;
	
	struct tile Tile81;
	Tile81.id = Dummy.id;
	Tile81.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile81.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile81.flags[0] = '\0';
	Tile81.flags[1] = '\0';
	Tile81.asset = Dummy.asset;
	
	struct tile Tile82;
	Tile82.id = Dummy.id;
	Tile82.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile82.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile82.flags[0] = '\0';
	Tile82.flags[1] = '\0';
	Tile82.asset = Dummy.asset;
	
	struct tile Tile83;
	Tile83.id = Dummy.id;
	Tile83.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile83.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile83.flags[0] = '\0';
	Tile83.flags[1] = '\0';
	Tile83.asset = Dummy.asset;
	
	struct tile Tile84;
	Tile84.id = Dummy.id;
	Tile84.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile84.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile84.flags[0] = '\0';
	Tile84.flags[1] = '\0';
	Tile84.asset = Dummy.asset;
	
	struct tile Tile85;
	Tile85.id = Dummy.id;
	Tile85.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile85.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile85.flags[0] = '\0';
	Tile85.flags[1] = '\0';
	Tile85.asset = Dummy.asset;
	
	struct tile Tile86;
	Tile86.id = Dummy.id;
	Tile86.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile86.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile86.flags[0] = '\0';
	Tile86.flags[1] = '\0';
	Tile86.asset = Dummy.asset;
	
	struct tile Tile87;
	Tile87.id = Dummy.id;
	Tile87.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile87.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile87.flags[0] = '\0';
	Tile87.flags[1] = '\0';
	Tile87.asset = Dummy.asset;
	
	struct tile Tile88;
	Tile88.id = Dummy.id;
	Tile88.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile88.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile88.flags[0] = '\0';
	Tile88.flags[1] = '\0';
	Tile88.asset = Dummy.asset;
	
	struct tile Tile89;
	Tile89.id = Dummy.id;
	Tile89.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile89.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile89.flags[0] = '\0';
	Tile89.flags[1] = '\0';
	Tile89.asset = Dummy.asset;
	
	struct tile Tile90;
	Tile90.id = Dummy.id;
	Tile90.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile90.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile90.flags[0] = '\0';
	Tile90.flags[1] = '\0';
	Tile90.asset = Dummy.asset;
	
	struct tile Tile91;
	Tile91.id = Dummy.id;
	Tile91.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile91.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile91.flags[0] = '\0';
	Tile91.flags[1] = '\0';
	Tile91.asset = Dummy.asset;
	
	struct tile Tile92;
	Tile92.id = Dummy.id;
	Tile92.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile92.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile92.flags[0] = '\0';
	Tile92.flags[1] = '\0';
	Tile92.asset = Dummy.asset;
	
	struct tile Tile93;
	Tile93.id = Dummy.id;
	Tile93.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile93.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile93.flags[0] = '\0';
	Tile93.flags[1] = '\0';
	Tile93.asset = Dummy.asset;
	
	struct tile Tile94;
	Tile94.id = Dummy.id;
	Tile94.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile94.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile94.flags[0] = '\0';
	Tile94.flags[1] = '\0';
	Tile94.asset = Dummy.asset;
	
	struct tile Tile95;
	Tile95.id = Dummy.id;
	Tile95.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile95.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile95.flags[0] = '\0';
	Tile95.flags[1] = '\0';
	Tile95.asset = Dummy.asset;
	
	struct tile Tile96;
	Tile96.id = Dummy.id;
	Tile96.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile96.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile96.flags[0] = '\0';
	Tile96.flags[1] = '\0';
	Tile96.asset = Dummy.asset;
	
	struct tile Tile97;
	Tile97.id = Dummy.id;
	Tile97.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile97.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile97.flags[0] = '\0';
	Tile97.flags[1] = '\0';
	Tile97.asset = Dummy.asset;
	
	struct tile Tile98;
	Tile98.id = Dummy.id;
	Tile98.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile98.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile98.flags[0] = '\0';
	Tile98.flags[1] = '\0';
	Tile98.asset = Dummy.asset;
	
	struct tile Tile99;
	Tile99.id = Dummy.id;
	Tile99.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		Tile99.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	Tile99.flags[0] = '\0';
	Tile99.flags[1] = '\0';
	Tile99.asset = Dummy.asset;

	struct tile local_tiles[100] = {Tile0, Tile1, Tile2, Tile3, Tile4, Tile5, Tile6, Tile7, Tile8, Tile9, 
		Tile10, Tile11, Tile12, Tile13, Tile14, Tile15, Tile16, Tile17, Tile18, Tile19, Tile20, 
		Tile21, Tile22, Tile23, Tile24, Tile25, Tile26, Tile27, Tile28, Tile29, Tile30, 
		Tile31, Tile32, Tile33, Tile34, Tile35, Tile36, Tile37, Tile38, Tile39, Tile40,
		Tile41, Tile42, Tile43, Tile44, Tile45, Tile46, Tile47, Tile48, Tile49, Tile50,
		Tile51, Tile52, Tile53, Tile54, Tile55, Tile56, Tile57, Tile58, Tile59, Tile60,
		Tile61, Tile62, Tile63, Tile64, Tile65, Tile66, Tile67, Tile68, Tile69, Tile70,
		Tile71, Tile72, Tile73, Tile74, Tile75, Tile76, Tile77, Tile78, Tile79, Tile80,
		Tile81, Tile82, Tile83, Tile84, Tile85, Tile86, Tile87, Tile88, Tile89, Tile90,
		Tile91, Tile92, Tile93, Tile94, Tile95, Tile96, Tile97, Tile98, Tile99};

	init_tiles(local_tiles);

	int pos[2] = { player.xpos, player.ypos };

	init_screen(screen);
	load_scene(TestZone, screen, tile_ids, ref, local_tiles, tile_frequency);
	load_tiles(tile_frequency, local_tiles, Dummy, Tiles);
	//system("PAUSE");
	print_screen(screen, pos, local_tiles, tile_ids);
	print_menu(TestText);
	load_settings(settings);
	print_tile_ids(tile_ids);
	print_frequency(tile_frequency);


	while (exit != 1)
	{
		input = _getche();

		update_location(tile_ids, ref, pos, input, local_tiles);
		input = '\0';
		system("cls");
		print_screen(screen, pos, local_tiles, tile_ids);
		print_menu(TestText);
		printf("Player position is %d %d.\n", pos[0], pos[1]);
	}

	return 0;
}