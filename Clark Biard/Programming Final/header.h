#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct profile
{
	char name[100];
	char plan;
	int talk_minutes;
	int data_MB;
	double charges;
	int order;
	int dummy_flag;
}Profile;

int init_arr(Profile dummy, Profile customers[100]);
int print_customers(Profile customers[100]);
int read_customers(FILE* infile, Profile customers[100]);
int sort_customers(Profile customers[100], Profile dummies[100]);