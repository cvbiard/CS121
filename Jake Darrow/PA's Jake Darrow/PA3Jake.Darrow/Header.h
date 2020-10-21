//throw all my functions in here to clean main up

#define _CRT_SECURE_NO_WARNINGS		//scanf doesn't give warnings
#include <stdio.h>					//scanf and printf and friends
#include <math.h>					//power function sqrt and friends

#define PI 3.14	//did this out of habit


//all my functions below to be called by main
double read_double(FILE* name);

int read_int(FILE* name);

void print_double(FILE* outfile, double number);

double calculate_sum(double number1, double number2, double number3, double number4, double number5);

double calculate_mean(double number1, double number2, double number3, double number4, double number5, int number);

double calculate_deviation(double number, double mean);

double calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number);

double calculate_standard_deviation(double variance);

double find_max(double number1, double number2, double number3, double number4, double number5);

double find_min(double number1, double number2, double number3, double number4, double number5);

