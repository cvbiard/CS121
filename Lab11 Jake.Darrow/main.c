#include "header.h"

typedef struct employee
{

    char name[100];      // employee's name - last, first

    char title;          // title 'B' or 'M'

    double hours_worked; // total number of hours worked

    double payrate;      // pay rate per hour

    double payment;      // total payment for the pay period – you will compute!

} Employee;


int main(void)
{
    Employee payroll[200]; // the input file may not exceed 200 employee records
    
    int counter = 0;
    int i = 0, j = 0, min = 0, max = 0;
    double sum = 0, average = 0;
    char buffer = '\0';

    Employee temp;

    FILE* fp, * ofp;
    fp = fopen("payroll.txt", "r");
    ofp = fopen("paid.txt", "w");

    //Reading data
    while (!feof(fp))
    {
        //Reading name
        fscanf(fp, "%[^\n]", temp.name);
        fscanf(fp, "%c", &buffer);
        fscanf(fp, "%[^\n]", &temp.title);
        fscanf(fp, "%lf", &temp.hours_worked);
        fscanf(fp, "%c", &buffer);
        fscanf(fp, "%lf", &temp.payrate);
        fscanf(fp, "%c", &buffer);

        //Adding to array
        payroll[counter] = temp;
        counter++;
    }

    //Iterating over array and computing payment
    for (i = 0; i < counter; i++)
    {
        payroll[i].hours_worked = payroll[i].hours_worked / 2.0;
        //Compute payment
        if (payroll[i].title == 'B')
        {
            if (payroll[i].hours_worked > 40)
            {
                payroll[i].payment = payroll[i].payrate * 40;
                payroll[i].payment += (1.5 * (payroll[i].hours_worked - 40) * payroll[i].payrate);
            }
            else
            {
                payroll[i].payment = payroll[i].payrate * payroll[i].hours_worked;
            }
        }
        else if (payroll[i].title == 'M')
        {
            if (payroll[i].hours_worked > 40)
            {
                payroll[i].payment = payroll[i].payrate * 40;
                payroll[i].payment += (1.8 * (payroll[i].hours_worked - 40) * payroll[i].payrate);
            }
            else
            {
                payroll[i].payment = payroll[i].payrate * payroll[i].hours_worked;
            }
        }

        payroll[i].payment = payroll[i].payment * 2.0;

        //Checking min and max salary
        if (i == 0)
        {
            min = 0;
            max = 0;
        }
        else
        {
            //Comparing payment
            if (payroll[i].payment < payroll[min].payment)
            {
                //Updating min
                min = i;
            }

            if (payroll[i].payment > payroll[max].payment)
            {
                //Updating max
                max = i;
            }
        }
        //Accumulating payment
        sum += payroll[i].payment;
    }

    //Computing average
    average = sum / (double)(counter);

    //Closing file
    fclose(fp);

    //Writing results
    fprintf(ofp, "Total: $%.2lf\n", sum);
    fprintf(ofp, "Average: $%.2lf\n", average);
    fprintf(ofp, "Max: $%.2lf\n", payroll[max].payment);
    fprintf(ofp, "Min: $%.2lf", payroll[min].payment);

    //Closing file
    fclose(ofp);

    return 0;
}