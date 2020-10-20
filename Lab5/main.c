#include"Lab5.h"



int main(void)
{
FILE* infile = fopen("Data.txt", "r");
double qs1 = 0.0, qs2 = 0.0, qs3 = 0.0, qs4 = 0.0, qss = 0.0;
char bracket = '\0';

qs1 = read_salary(infile);
qs2 = read_salary(infile);
qs3 = read_salary(infile);
qs4 = read_salary(infile);

qss = sum(qs1,qs2,qs3,qs4);

bracket = determine_bracket(qss);

printf("Income bracket: %c\n", bracket);
}