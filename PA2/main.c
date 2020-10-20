/*
Author: Clark Biard
Date Created: 9/9/2020
Description: This program was created as a solution for the assignment PA1. Created in collaboration with Jake Darrow and Kathrine Hubbard.
*/

#include "PA2.h"


int main(void)

{

	//Problem 1
	int R1 = 0, R2 = 0, R3 = 0, result1 = 0;

	printf("Please enter three integers for R1, R2, and R3\n");
	scanf("%d%d%d", &R1, &R2, &R3);

	result1 = series_resistance(R1, R2, R3);

	printf("Series Resistance: %d\n", result1);

	//Problem 2
	double sales_tax_rate = 0.0, item_cost = 0.0, result2 = 0.0;
	printf("Please enter values for item cost and sales tax rate:\n");
	scanf("%lf%lf", &item_cost, &sales_tax_rate);

	result2 = total_sales_tax(sales_tax_rate, item_cost);

	printf("Total sales tax: %lf\n", result2);

	//Problem 3
	double l = 0.0, h = 0.0, w = 0.0, result3 = 0;
	printf("Please enter values for pyramid length, height, and width\n");
	scanf("%lf%lf%lf", &l, &h, &w);

	result3 = volume_pyramid(l, h, w);

	printf("Pyramid volume: %lf\n", result3);

	//Problem 4
	double Resistor1 = 0.0, Resistor2 = 0.0, Resistor3 = 0.0, result4 = 0.0;

	printf("Please enter three floats for R1, R2, and R3\n");
	scanf("%lf%lf%lf", &Resistor1, &Resistor2, &Resistor3);

	result4 = parallel_resistance(Resistor1, Resistor2, Resistor3);

	printf("Series Resistance: %lf\n", result4);

	//Problem 5
	char plaintext_character = '\0';
	int shift_int = 0, result5 = 0;

	printf("Please enter a plaintext character and a shift integer\n");
	scanf("%c%d", &plaintext_character, &shift_int);

	result5 = ((int)plaintext_character - 'a') + ('A' - shift_int);
	printf("Encoded Character: %d\n", result5);

	//Problem 6
	double x1 = 0.0, x2 = 0.0, y1 = 0.0, y2 = 0.0, result6 = 0.0;
	printf("Please enter values for x1, x2, y1, and y2\n");
	scanf("%lf%lf%lf%lf", &x1, &x2, &y1, &y2);

	result6 = distance(x1, x2, y1, y2);
	printf("Distance: %lf\n", result6);

	//Problem 7
	double z = 0.0, x = 0.0, result7 = 0.0;
	int a = 0;
	printf("Please enter values for z, x, and a\n");
	scanf("%lf%lf%d", &z, &x, &a);
	result7=solution(z, x, a);
	printf("y: %lf\n", result7);


	return 0;
}

