#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct employee
{
    char name[100];      // employee's name - last, first
    char title;          // title 'B' or 'M'
    double hours_worked; // total number of hours worked
    double payrate;      // pay rate per hour
    double payment;      // total payment for the pay period – you will compute!
} Employee;

typedef struct totals
{
    double total;
    double average;
    double max;
    double min;
}Totals;

int read_info(FILE* input, Employee payroll[200]);
void compute(Employee payroll[200], int count, Totals arr[1]);
void print_info(FILE* output, Totals arr[1]);