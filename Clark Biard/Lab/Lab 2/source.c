#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int  main(void)
{
	//Perpendicular Bisector Calculation
	int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
	double slope_initial = 0.0, slope_bisector = 0.0, midpointx = 0.0, midpointy = 0.0, yintercept = 0.0;

	printf("Please enter two end points of a line you would like to find the perpendicular bisector to.\nEnter them in the order of x1, y1, x2, y2.\n");
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

	slope_initial = ((double)y2 - (double)y1) / ((double)x2 - (double)x1);

	midpointx = (x1 + x2) / 2;
	midpointy = (y1 + y2) / 2;

	slope_bisector = -((x2 - x1) / (y2 - y1));

	yintercept = midpointy - (slope_bisector * midpointx);

	printf("For the initial points (%d, %d) and (%d, %d), the slope is %.1lf.\nThe midpoint of this line is (%.1lf, %.1lf).\nThe slope of the perpendicular bisector is %.1lf.\nFinally, the formula for the perpendicular bisector is y=%.1lfx+%.1lf.\n", x1, y1, x2, y2, slope_initial, midpointx, midpointy, slope_bisector, slope_bisector, yintercept);
	

	//BMI Calculation
	
	int height = 0;
	double weight = 0.0, bmi = 0.0;

	printf("Please enter your height in feet and weight in pounds to calculate your BMI.\n");
	scanf("%d%lf", &height, &weight);

	height = height * 12;

	bmi = ((weight / pow(height, 2)) * 703);

	printf("Your BMI is %.2lf.\n", bmi);

	//BCS Calculation
	int harris = 0, coach = 0;
	double computer_ranking = 0.0, BCS_score = 0.0, harris_poll = 0.0, coaches_poll = 0.0;

	printf("Please enter a Harris Poll rank, Coaches Poll rank and computer ranking to calculate a team's Bowl Championship Series score.\n");
	scanf("%d%d%lf", &harris, &coach, &computer_ranking);

	harris_poll = (double)harris / 2850;
	coaches_poll = (double)coach / 1475;

	BCS_score = (harris_poll + coaches_poll + computer_ranking) / 3;

	printf("The Harris Poll is %.2lf.\nThe Coaches Poll is %.2lf.\nThe BCS Score is %.2lf.\n", harris_poll, coaches_poll, BCS_score);

	return 0;
}