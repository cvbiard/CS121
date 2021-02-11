#include "header.h"

double calculate_newtons_2nd_law(double mass, double acceleration)
{
	return mass * acceleration;
}
double calculate_volume_cylinder(double radius, double height)
{
	return PI * (pow(radius, 2)) * height;
}
char encode_character(char plaintext_char, int shift)
{
	return (plaintext_char - 'A') + 'a' - shift;
}
double calculate_distance(double x1, double x2, double y1, double y2)
{
	return sqrt((pow((x1 - x2), 2) + (pow((y1 - y2), 2))));
}
double calculate_tan(double angle)
{
	return sin(angle) / cos(angle);
}
double calculate_resistance(int R1, int R2, int R3)
{
	return 1 / ((1 / (double)R1) + (1 / (double)R2) + (1 / (double)R3));
}
double calculate_equation(int a, double x, double z)
{
	double y = 0;
	y = (((2 / 3) - y + z * x) / ((a % 2) + PI));
	return y;
}
