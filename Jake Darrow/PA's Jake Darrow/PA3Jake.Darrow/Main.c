//PA3, CptS 121
//Created by: Jake Darrow on 9/21/20
//This program calculates various statistics using student infomration

#include "header.h" //Functions stored seperately for organization

int main(void)

{

	FILE* infile = fopen("input.dat", "r"); //reads information from "input.dat"
	FILE* outfile = fopen("output.dat", "w"); //writes information to "output.dat"

	//establishing all the double float variables and integer variables used within main
	double number1 = 4.0, number2 = 5.0, number3 = 5.0, number4 = 5.0, number5 = 5.0, 
		sum = 0.0, mean = 0.0, 
		deviation1 = 0.0, deviation2 = 0.0, deviation3 = 0.0, deviation4 = 0.0, deviation5 = 0.0, 
		variance=0.0, stdev=0.0, maximum=0.0, minimum = 0.0, gpa_sum=0.0, gpa_mean=0.0, class_mean=0.0, age_mean=0.0, 
		dev1=0.0, dev2=0.0, dev3=0.0, dev4=0.0, dev5=0.0, var=0.0, stdev_g=0.0, min_g=0.0, max_g=0.0;
	int number = 5;

	double age1 = 0.0, age2 = 0.0, age3 = 0.0, age4 = 0.0, age5 = 0.0, 
		   gpa1 = 0.0, gpa2 = 0.0, gpa3 = 0.0, gpa4 = 0.0, gpa5 = 0.0, age_sum =0.0;

	int id1 = 0, id2 = 0, id3 = 0, id4 = 0, id5 = 0, class1 = 0, class2=0, class3=0, class4=0, class5=0, class_sum=0.0;

	id1 = read_int(infile);			//scans all values from infile
	gpa1 = read_double(infile);
	class1 = read_int(infile);
	age1 = read_double(infile);

	id2 = read_int(infile);
	gpa2 = read_double(infile);
	class2 = read_int(infile);
	age2 = read_double(infile);

	id3 = read_int(infile);
	gpa3 = read_double(infile);
	class3 = read_int(infile);
	age3 = read_double(infile);

	id4 = read_int(infile);
	gpa4 = read_double(infile);
	class4 = read_int(infile);
	age4 = read_double(infile);

	id5 = read_int(infile);
	gpa5 = read_double(infile);
	class5 = read_int(infile);
	age5 = read_double(infile);

	//sum function
	sum = calculate_sum(number1, number2, number3, number4, number5);
	printf("%lf\n", sum);

	//saftey check (:
	if (number != 0)
	{
	mean = calculate_mean(number1, number2, number3, number4, number5, number);
	printf("%lf\n", mean);
	}
	else
	{
		printf("number cannot equal zero");
	}

	//calculates deviation values
	deviation1 = calculate_deviation(number1, mean);
	deviation2 = calculate_deviation(number2, mean);
	deviation3 = calculate_deviation(number3, mean);
	deviation4 = calculate_deviation(number4, mean);
	deviation5 = calculate_deviation(number5, mean);
	printf("%lf%lf%lf%lf%lf\n", deviation1, deviation2, deviation3, deviation4, deviation5); //safety check

	variance = calculate_variance(deviation1, deviation2, deviation3, deviation4, deviation5, number); 
	printf("%lf\n", variance);	//safety check

	stdev = calculate_standard_deviation(variance);

	printf("%lf\n", stdev);	//saftey check

	maximum = find_max(number1, number2, number3, number4, number5);
	printf("%lf\n", maximum);	//saftey check

	minimum = find_min(number1, number2, number3, number4, number5);
	printf("%lf\n", minimum);	//saftey check


	gpa_sum = calculate_sum(gpa1, gpa2, gpa3, gpa4, gpa5);
	fprintf(outfile, "gpa sum is: %.2lf\n", gpa_sum);	//ships print to outfile

	class_sum = calculate_sum(class1, class2, class3, class4, class5); 

	age_sum = calculate_sum(age1, age2, age3, age4, age5);

	gpa_mean = calculate_mean(gpa1, gpa2, gpa3, gpa4, gpa5, number);
	fprintf(outfile, "average gpa is: %.2lf\n", gpa_mean);

	class_mean = calculate_mean(class1, class2, class3, class4, class5, number);
	fprintf(outfile, "average class is: %.2lf\n", class_mean);

	age_mean = calculate_mean(age1, age2, age3, age4, age5, number);
	fprintf(outfile, "average age is: %.2lf\n", age_mean);

	dev1 = calculate_deviation(gpa1, gpa_mean);
	dev2 = calculate_deviation(gpa2, gpa_mean);
	dev3 = calculate_deviation(gpa3, gpa_mean);
	dev4 = calculate_deviation(gpa4, gpa_mean);
	dev5 = calculate_deviation(gpa5, gpa_mean);

	// fprintf(outfile, "deviation values %lf%lf%lf%lf%lf\n", dev1, dev2, dev3, dev4, dev5); test to check deviation values

	var = calculate_variance(dev1, dev2, dev3, dev4, dev5, number);
	fprintf(outfile, "variance in GPA is: %.2lf\n", var);	//ships values to outfile

	stdev_g = calculate_standard_deviation(var);
	fprintf(outfile, "standard deviation is: %.2lf\n", stdev_g);

	min_g = find_min(gpa1, gpa2, gpa3, gpa4, gpa5);
	fprintf(outfile, "min GPA is: %.2lf\n", min_g);

	max_g = find_max(gpa1, gpa2, gpa3, gpa4, gpa5);
	fprintf(outfile, "max GPA is: %.2lf\n", max_g);

	fclose(infile);			//closes files up so computer doesn't explode
	fclose(outfile);
	return 0;		//success
}