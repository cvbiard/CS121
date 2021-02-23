#ifndef HEADER_H // guard code
#define HEADER_H
#define _CRT_SECURE_NO_WARNINGS
#define G 32.17

#include <stdio.h>
#include <math.h>


double get_weight();
double get_height_in_feet();
double convert_feet_to_inches(double height_in_feet);
double calculate_bmi(double weight_in_pounds, double height_in_feet);
void display_bmi();
double get_theta();
double get_distance();
double get_velocity();
double calculate_time(double theta, double distance, double velocity);
double calculate_height(double theta, double distance, double velocity);
void display_results();
double get_score();
double calculate_average(double score1, double score2);
void display_total();

#endif