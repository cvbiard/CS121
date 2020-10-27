#include "header.h"

int read_int(FILE* name)
{
	int vari2;
	fscanf(name, "%d", &vari2);
	return vari2;
}

void print_int(FILE* outfile, int number)
{
	fprintf(outfile, "%lf", number);
}

int add_integers(FILE* infile)
{
	int integer[] = 0, num = 0;

	for (int i = 0; integer != EOF; i++)
	{
		fscanf(infile, "%d", &integer);
	}
}