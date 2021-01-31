#include "header.h"


int main(void)
{

	FILE* settings = fopen("settings.txt", "r");
	char screen[width][height], input = '\0';
	

	int exit = 0;

	struct object player;
	player.xpos = 0;
	player.ypos = 0;
	
	FILE* scene = fopen("TestZone.txt", "r");

	int pos[2] = { player.xpos, player.ypos };
	
	char prev = '\0';

	init_screen(screen);
	load_scene(scene, screen);
	print_screen(screen, pos);
	load_settings(settings);

	while (exit != 1)
	{
		input = _getche();

		prev = update_location(screen, pos, input, prev);
		input = '\0';
		system("cls");
		print_screen(screen, pos);
		printf("Player position is %d %d.\n", pos[0], pos[1]);
	}

	return 0;
}