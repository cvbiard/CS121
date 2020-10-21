/*
Made by: Jake Darrow
Remade on 9/30/20
Description: This program provides solutions to the various problems presented in PA1.
*/

//Allows scanf to work without warnings
#define _CRT_SECURE_NO_WARNINGS

//includes premade functions like scanf printf and pow
#include <stdio.h>
#include <math.h>

//defines value of pi
#define PI 3.14


int main(void)

{
	//Problem #1
	//define integer values
	int R1 = 0, R2 = 0, R3 = 0, series_resistance = 0;

	//prompts user to enter values for initialized variables, then scans and stores values user provided to respective variable
	printf("enter integer values for R1, R2, and R3\n");
	scanf("%d%d%d", &R1, &R2, &R3);

	//math function providing answer
	series_resistance = R1 + R2 + R3;

	//reads answer to user
	printf("series resistance is: %d\n", series_resistance);


	//Problem #2

	//define variable as double instead because items usually have prices with decimals
	double sales_tax_rate = 0.0, item_cost = 0.0, total_sales_tax = 0.0;

	//prompts user to enter values for double variables, then scans and stores values user provided to respective variable
	printf("enter values for item cost and sales tax rate:\n");
	scanf("%lf%lf", &item_cost, &sales_tax_rate);

	//math function to solve problem
	total_sales_tax = item_cost * sales_tax_rate;

	//Reads answer to problem back to user
	printf("total sales tax is: %lf\n", total_sales_tax);


	//Problem #3

	//define double variables and assign value so they have meaning
	double l = 0.0, h = 0.0, w = 0.0, volume_pyramid = 0.0;

	//prompts user to enter values for double variables, then scans and stores values user provided to respective variable
	printf("enter pyramid dimensions\n");
	scanf("%lf%lf%lf", &l, &h, &w);

	//math time
	volume_pyramid = (l * w * h) / 3;

	//Reads answer back to user
	printf("pyramid volume is: %lf\n", volume_pyramid);


	//Problem #4

	//define new resistance variables as doubles
	double R4 = 0.0, R5 = 0.0, R6 = 0.0, parallel_resistance = 0.0;

	//prompts user to enter r values then reads/stores values to respective variables
	printf("enter three floats for R4, R5, and R6\n");
	scanf("%lf%lf%lf", &R4, &R5, &R6);

	//math function
	parallel_resistance = 1 / ((1 / R4) + (1 / R5) + (1 / R6));

	printf("series resistance is: %lf\n", parallel_resistance);

	//Problem #5

	//define variables, new type char
	char plaintext_character = '\0';
	int shift_int = 0, encoded_character = 0;

	//prompts user to enter r values then reads/stores values to respective variables
	printf("enter a plaintext character and a shift integer\n");
	scanf(" %c%d", &plaintext_character, &shift_int);

	//Computer operation called for in problem
	encoded_character = ((int)plaintext_character - 'a') + ('A' - shift_int);

	//reads answer back to user
	printf("encoded character is: %d\n", encoded_character);


	//Problem #6

	//defines and assigns value to variables for problem
	double x1 = 0.0, x2 = 0.0, y1 = 0.0, y2 = 0.0, distance = 0.0;

	//prompts user to enter r values then reads/stores values to respective variables
	printf("enter values for x1, x2, y1, and y2\n");
	scanf("%lf%lf%lf%lf", &x1, &x2, &y1, &y2);

	//math function to obtain answer
	distance = sqrt((pow((x1 - x2), 2) + pow((y1 - y2), 2)));

	//reads answer back to user
	printf("distance is: %lf\n", distance);


	//Problem #7

	//define double and int variables/assign them value
	double z = 0.0, x = 0.0, y = 0.0;
	int a = 0;

	////prompts user to enter r values then reads/stores values to respective variables
	printf("enter values for z, x, and a\n");
	scanf("%lf%lf%d", &z, &x, &a);

	//math function
	y = (y / ((float)3 / (float)17) - z) + (x / (a % 2) + PI);

	//provides answer to user
	printf("y is: %lf\n", y);


	return 0;
}
