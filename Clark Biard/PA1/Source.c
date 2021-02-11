#define _CRT_SECURE_NO_WARNINGS
#define PI 3.14

#include <stdio.h>
#include <math.h>



int main(void)
{

	//Newton's Law
	double mass = 0.0, accel = 0.0, force = 0.0;
	printf("Please enter values for mass and acceleration, to use in solving for force in Newton's Second Law.\n");
	scanf("%lf%lf", &mass, &accel);

	force = mass * accel;
	
	printf("Force is %lf.\n", force);

	//Cylinder 
	double radius = 0.0, height = 0.0, volume = 0.0;

	printf("Please enter a height and radius for use in calculating the volume of a cylinder.\n");
	scanf("%lf%lf", &radius, &height);

	volume = PI * (pow(radius, 2)) * height;

	printf("The volume is %lf.\n", volume);

	//Character encoding
	int shift = 0;
	char plaintext_character = '\0', encoded_character = '\0';

	printf("Please enter a shift integer and a plaintext character.\n");
	scanf("%d%c%*c", &shift, &plaintext_character);

	encoded_character = (plaintext_character - 'A') + 'a' - shift;

	printf("Encoded character is %c.\n", encoded_character);

	//Distance between two points
	double x1 = 0, x2 = 0, y1 = 0, y2 = 0, distance = 0;

	printf("Please enter two sets of coordinates (x, y).\n");
	scanf("%lf%lf%lf%lf", &x1, &x2, &y1, &y2);

	distance = sqrt((pow((x1 - x2), 2) + (pow((y1 - y2), 2))));

	printf("Distance is %lf.\n", distance);

	//Tangent
	double theta = 0, tan_theta = 0.0;

	printf("Please enter a theta angle to find the tangent of.\n");
	scanf("%lf", &theta);

	tan_theta = sin(theta) / cos(theta);

	printf("The tangent is %lf.\n", tan_theta);

	//Series resistance
	int R1 = 0, R2 = 0, R3 = 0;
	double resistance = 0.0;

	printf("Please enter three values to calculate series resistance.\n");
	scanf("%d%d%d", &R1, &R2, &R3);

	resistance = 1/((1 / (double)R1) + (1 / (double)R2) + (1 / (double)R3));

	printf("Resistance is %lf.\n", resistance);

	//General equation
	int a = 0;
	double x = 0, y = 0, z = 0;

	printf("Please enter an integer and two floats for a, x, and z in the equation y = (2 / 3) - y + z * x / (a %% 2) + PI.\n");
	scanf("%d%lf%ld", &a, &x, &z);

	y = (((2 / 3) - y + z * x) / ((a % 2) + PI));

	printf("The solution is %lf.\n", y);

	return 1;
}