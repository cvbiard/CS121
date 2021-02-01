#include "header.h"


int main(void)
{

	FILE* settings = fopen("settings.txt", "r");
	char screen[width][height], ref[width][height], functional[width][height], input = '\0';
	char TestText[] = "This is test text, and I'm making it long to see what happens :)";
	

	int exit = 0;

	struct object player;
	player.xpos = 0;
	player.ypos = 0;
	
	struct asset TestZone;
	TestZone.visual_asset = fopen("TestZoneV.txt", "r");
	TestZone.functional_asset = fopen("TestZoneF.txt", "r");

	int pos[2] = { player.xpos, player.ypos };

	init_screen(screen);
	init_screen(ref);
	init_screen(functional);
	load_scene(TestZone, screen, ref, functional);
	print_screen(screen, pos);
	print_menu(TestText);
	load_settings(settings);


	while (exit != 1)
	{
		input = _getche();

		update_location(screen, ref, functional, pos, input);
		input = '\0';
		system("cls");
		print_screen(screen, pos);
		print_menu(TestText);
		printf("Player position is %d %d.\n", pos[0], pos[1]);
	}

	return 0;
}