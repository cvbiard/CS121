#include "header.h"

double get_weight()
{
	double weight = 0.0;
	printf("Please enter your weight in pounds.\n");
	scanf("%lf", &weight);
	return weight;
}
double get_height_in_feet()
{
	double height = 0.0;
	printf("Please enter your height in feet.\n");
	scanf("%lf", &height);
	return height;
}
double convert_feet_to_inches(double height_in_feet)
{
	double height_in_inches = 0.0;
	height_in_inches = height_in_feet * 12;
	return height_in_inches;
}
double calculate_bmi(double weight_in_pounds, double height_in_feet)
{
	double BMI = 0.0, height_in_inches = 0.0;

	height_in_inches = convert_feet_to_inches(height_in_feet);

	BMI = weight_in_pounds/(pow((height_in_inches), 2)) * 703;

	return BMI;
}
void display_bmi()
{
	printf("Your BMI is %lf.\n", calculate_bmi(get_weight(), get_height_in_feet()));
}
double get_theta()
{
	double theta = 0.0;
	printf("Please enter an angle in radians.\n");
	scanf("%lf", &theta);

	return theta;
}
double get_distance()
{
	double distance = 0.0;
	printf("Please enter a distance in feet.\n");
	scanf("%lf", &distance);

	return distance;
}
double get_velocity()
{
	double velocity = 0.0;
	printf("Please enter a velocity in m/s.\n");
	scanf("%lf", &velocity);

	return velocity;
}
double calculate_time(double theta, double distance, double velocity)
{
	double time = 0.0;
	time = (distance) / (velocity * cos(theta));
	if (time < 0)
	{
		time = time * (-1);
	}
	printf("The time is %lf.\n", time);

	return time;
}
double calculate_height(double theta, double distance, double velocity)
{
	double height = 0.0, time = 0.0;

	time = calculate_time(theta, distance, velocity);

	height = velocity * sin(theta) * time - ((G * pow(time,2) / 2));

	return height;

}
void display_results()
{
	printf("The height is %lf.\n", calculate_height(get_theta(), get_distance(), get_velocity()));
}
double get_score()
{
	double score = 0.0;
	printf("Please enter a score out of 100.\n");
	scanf("%lf", &score);

	return score;
}
double calculate_average(double score1, double score2)
{
	return (score1 + score2) / 2;
}
double calculate_weighted_total(double exam_avg, double lab_avg, double project_avg)
{
	double weighted_exam = 0.0, weighted_lab = 0.0, weighted_project = 0.0, total = 0.0;

	weighted_exam = exam_avg * (.3);

	weighted_lab = lab_avg * (.05);

	weighted_project = project_avg * (.15);

	total = weighted_exam + weighted_lab + weighted_project;

	return total;
}
void display_total()
{
	double exam_avg = 0.0, lab_avg = 0.0, project_avg = 0.0;

	printf("Exams:\n");
	exam_avg = calculate_average(get_score(), get_score());

	printf("Labs:\n");
	lab_avg = calculate_average(get_score(), get_score());

	printf("Projects:\n");
	project_avg = calculate_average(get_score(), get_score());

	printf("Your total out of 100%% is %lf.\n", calculate_weighted_total(exam_avg, lab_avg, project_avg));
}
