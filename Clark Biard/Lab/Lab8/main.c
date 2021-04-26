#include "header.h"

int main(void)
{
	FILE* input = fopen("in.txt", "r");
	int arr[1] = { 0 };
	int arr2[20];
	int ft[101];
	int letters_guessed[5] = { 0,0,0,0,0 };
	int man_counter = 0;
	int win = 0;

	char word[5] = { 'h', 'o', 'u', 's', 'e' };

	srand(time(0));

	//Problem 1
	read_to_array(arr, input);
	
	//Problem 2
	populate_array(arr2);
	print_arr(arr2, 20);
	frequency(arr2, ft);
	print_arr(ft, 101);

	//Problem 3
	while (win == 0)
	{
		system("cls");
		print_hangman(man_counter, word, letters_guessed);
		man_counter = man_counter + get_guess(word, letters_guessed);
		win = check_win(letters_guessed);

		if (man_counter == 6)
		{
			printf("You lose!\n");
			return 0;
		}
	}

	printf("You won!\n");
	return 0;
	

}