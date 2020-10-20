#include "PA2.h"

int series_resistance(int R1, int R2, int R3)
{
	return R1 + R2 + R3;
}

double total_sales_tax(double sales_tax_rate, double item_cost)
{
	return item_cost* sales_tax_rate;
}

double volume_pyramid(double l, double h, double w)
{
	return (l * h * w) / 3;
}

double parallel_resistance(double Resistor1, double Resistor2, double Resistor3)
{
	return 1 / ((1 / Resistor1) + (1 / Resistor2) + (1 / Resistor3));
}

int encoded_character(char plaintext_character, int shift_int)
{
	return ((int)plaintext_character - 'a') + ('A' - shift_int);
}

double distance(double x1, double x2, double y1, double y2)
{
	return  sqrt((pow((x1 - x2), 2) + pow((y1 - y2), 2)));
}

double solution(double z, double x, int a)
{
	double y = 0.0;
	y = y / ((float)3 / (float)17) - z + (x / (a % 2) + PI);

	return y;
}