#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void read_to_array(int arr[], FILE* input);
void populate_array(int arr[]);
void frequency(int arr[], int ft[]);
void print_arr(int arr[], int number);