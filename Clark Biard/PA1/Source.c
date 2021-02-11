#include "header.h"

int main(void)
{

	//Newton's Law
	double mass = 0.0, accel = 0.0, force = 0.0;
	printf("Please enter values for mass and acceleration, to use in solving for force in Newton's Second Law.\n");
	scanf("%lf%lf", &mass, &accel);

	printf("Force is %.2lf.\n", calculate_newtons_2nd_law(mass, accel));

	//Cylinder 
	double radius = 0.0, height = 0.0, volume = 0.0;

	printf("Please enter a height and radius for use in calculating the volume of a cylinder.\n");
	scanf("%lf%lf", &radius, &height);

	printf("The volume is %.2lf.\n", calculate_volume_cylinder(radius, height));

	//Character encoding
	int shift = 0;
	char plaintext_character = '\0', encoded_character = '\0';

	printf("Please enter a shift integer and a plaintext character.\n");
	scanf("%d%c%*c", &shift, &plaintext_character);

	printf("Encoded character is %c.\n", encode_character(plaintext_character, shift));

	//Distance between two points
	double x1 = 0, x2 = 0, y1 = 0, y2 = 0, distance = 0;

	printf("Please enter two sets of coordinates (x, y).\n");
	scanf("%lf%lf%lf%lf", &x1, &x2, &y1, &y2);

	printf("Distance is %.2lf.\n", calculate_distance(x1, x2, y1, y2));

	//Tangent
	double theta = 0, tan_theta = 0.0;

	printf("Please enter a theta angle to find the tangent of.\n");
	scanf("%lf", &theta);

	printf("The tangent is %.2lf.\n", calculate_tan(theta));

	//Series resistance
	int R1 = 0, R2 = 0, R3 = 0;
	double resistance = 0.0;

	printf("Please enter three values to calculate series resistance.\n");
	scanf("%d%d%d", &R1, &R2, &R3);

	printf("Resistance is %.2lf.\n", calculate_resistance(R1, R2, R3));

	//General equation
	int a = 0;
	double x = 0, y = 0, z = 0;

	printf("Please enter an integer and two floats for a, x, and z in the equation y = (2 / 3) - y + z * x / (a %% 2) + PI.\n");
	scanf("%d%lf%lf", &a, &x, &z);

	printf("The solution is %.2lf.\n", calculate_equation(a, x, z));

	return 1;
}