#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

typedef struct post
{
	int disk1;
	int disk2;
	int disk3;
}Post;

int maze(char maze[8][8], int pos[2]);
int sum_digits(int number);
void reverse_string(char *string, int start, int end);
int tower_game(Post tower[3]);