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
	int order; //Added this to use in sort_customers as a way to keep a customer's potential place in the line associated with their profile.
	int dummy_flag; //Added to easily be able to differentiate a dummy profile used for initialization from an actual profile. 0 = real profile, 1 = dummy.
	double avg_charge; //Added to keep track of the average charge per customer. Not because it's actually useful, just because I didn't know how to interpret the requirements and wanted to include both to be safe.
}Profile;

int init_arr(Profile dummy, Profile customers[100]);
int print_customers(Profile customers[100]);
int read_customers(FILE* infile, Profile customers[100]);
int sort_customers(Profile customers[100], Profile dummies[100]);
int calculate_charges(Profile customers[100]);
int calculate_stats(Profile customers[100], FILE* outfile);