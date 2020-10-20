#include "PA3.h"


int main(void)
{
	FILE*infile = fopen("input.dat", "r"),*outfile = fopen("output.dat", "w");
	double gpa_mean = 0.0, cs_mean = 0.0, age_mean = 0.0,
		   gpa_sd = 0.0, gpa_min = 0.0, gpa_max = 0.0,
		   gpa1 = 0.0, gpa2 = 0.0, gpa3 = 0.0, gpa4 = 0.0, gpa5 = 0.0,
		   gpa1d = 0.0, gpa2d = 0.0, gpa3d = 0.0, gpa4d = 0.0, gpa5d = 0.0,
		   gpav = 0.0,
		   age1 = 0.0, age2 = 0.0, age3 = 0.0, age4 = 0.0, age5 = 0.0;
	int number = 5,
		id1 = 0, id2 = 0, id3 = 0, id4 = 0, id5 = 0,
		cs1 = 0, cs2 = 0, cs3 = 0, cs4 = 0, cs5 = 0;

	id1 = read_int(infile);
	gpa1 = read_double(infile);
	cs1 = read_int(infile);
	age1 = read_double(infile);
	id2= read_int(infile);
	gpa2 = read_double(infile);
	cs2 = read_int(infile);
	age2 = read_double(infile);
	id3 = read_int(infile);
	gpa3 = read_double(infile);
	cs3 = read_int(infile);
	age3 = read_double(infile);
	id4 = read_int(infile);
	gpa4 = read_double(infile);
	cs4 = read_int(infile);
	age4 = read_double(infile);
	id5 = read_int(infile);
	gpa5 = read_double(infile);
	cs5 = read_int(infile);
	age5 = read_double(infile);

	gpa_mean = calculate_mean(calculate_sum(gpa1, gpa2, gpa3, gpa4, gpa5), 5);
	cs_mean = calculate_mean(calculate_sum(cs1, cs2, cs3, cs4, cs5), 5);
	age_mean = calculate_mean(calculate_sum(age1, age2, age3, age4, age5), 5);

	gpa1d = calculate_deviation(gpa1, gpa_mean);
	gpa2d = calculate_deviation(gpa2, gpa_mean);
	gpa3d = calculate_deviation(gpa3, gpa_mean);
	gpa4d = calculate_deviation(gpa4, gpa_mean);
	gpa5d = calculate_deviation(gpa5, gpa_mean);

	gpav = calculate_variance(gpa1d, gpa2d, gpa3d, gpa4d, gpa5d, 5);
	gpa_sd = calculate_standard_deviation(gpav);
	gpa_min = find_min(gpa1, gpa2, gpa3, gpa4, gpa5);
	gpa_max = find_max(gpa1, gpa2, gpa3, gpa4, gpa5);


	print_double(outfile, gpa_mean);
	print_double(outfile, cs_mean);
	print_double(outfile, age_mean);
	fprintf(outfile, "\n");
	print_double(outfile, gpa_sd);
	print_double(outfile, gpa_min);
	print_double(outfile, gpa_max);
	return 0;
}