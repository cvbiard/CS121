//definintion of all my functions controlling what exactly they do

#include "Header.h"

double read_double(FILE* name)
{
	double vari = 0.0;
	fscanf(name, "%lf", &vari);
	return vari;
}

int read_int(FILE* name)
{
	int vari2;
	fscanf(name, "%d", &vari2);
	return vari2;
}

void print_double(FILE* outfile, double number)
{
	fprintf(outfile, "%lf", number);
}

double calculate_sum(double number1, double number2, double number3, double number4, double number5)
{
	return(number1 + number2 + number3 + number4 + number5);
}

double calculate_mean(double number1, double number2, double number3, double number4, double number5, int number)
{
	return((number1 + number2 + number3 + number4 + number5) / number);
}

double calculate_deviation(double number1, double mean)
{
	return(number1-mean);
}

double calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number)
{
	return((pow(deviation1, 2) + pow(deviation2, 2) + pow(deviation3, 2) + pow(deviation4, 2) + pow(deviation5, 2)) / number);
}

double calculate_standard_deviation(double variance)
{
	return sqrt(variance);
}

double find_max(double number1, double number2, double number3, double number4, double number5) //if number 1 is greater than number2 then check if its greater than number....
{
	double max = 0.0;
	
	
	if (number1 >= number2 && number1 >= number3 && number1 >= number4 && number1 >= number5)
	{
		max = number1;
	}
	else if (number2 >= number3 && number2 >= number4 && number2 >= number5)
	{
		max = number2;
	}
	else if (number3 >= number4 && number3 >= number5)
	{
		max = number3;
	}
	else if (number4 >= number5)
	{
		max = number4;
	}
	else
	{
		max = number5;
	}

	return max;
}

double find_min(double number1, double number2, double number3, double number4, double number5)
{
	double min = 0.0;


	if (number1 <= number2 && number1 <= number3 && number1 <= number4 && number1 <= number5)
	{
		min = number1;
	}
	else if (number2 <= number3 && number2 <= number4 && number2 <= number5)
	{
		min = number2;
	}
	else if (number3 <= number4 && number3 <= number5)
	{
		min = number3;
	}
	else if (number4 <= number5)
	{
		min = number4;
	}
	else
	{
		min = number5;
	}

	return min;

}


