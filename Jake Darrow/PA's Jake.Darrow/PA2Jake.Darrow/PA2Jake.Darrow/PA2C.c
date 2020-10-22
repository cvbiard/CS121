#include "PA2header.h"


int series_resistance(int R1, int R2, int R3)
{
	return R1 + R2 + R3;
}

double total_sales_tax(double sales_tax_rate, double item_cost)
{
	return sales_tax_rate * item_cost;
}

double volume(double l, double w, double h)
{
	return l * w * h;
}

double parallel_resistance(double R4, double R5, double R6)
{
	return (1 / (float)R4) + (1 / (float)R5) + (1 / (float)R6);
}

int encoded_character(char plaintext_character, int shift_int)
{
	return ((int)(plaintext_character - 'a') + 'A' - shift_int);
}

double distance(double x1, double x2, double y1, double y2)
{
	return sqrt((pow((x1 - x2), 2) + pow((y1 - y2), 2)));
}

double answer(double z, double x, int a)
{
	double y = 0.0;
	y = ((y / ((float)3 / (float)17)) - z) + ((x / (a % 2)) + PI);
	return y;
}