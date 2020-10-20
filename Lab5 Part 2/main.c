#include "Lab5.h"

int main(void)

{

    FILE* infile = fopen("Data.txt", "r");
    FILE* outfile = fopen("output.txt", "w");
    double sum = 0.0, average = 0.0;
    int count = 0;



   
    while (!feof(infile))
    {
        sum = sum + read_number(infile);
        count = count + 1;
    }


    average = calc_average(sum, count);

    print_number(outfile, average);
   

}