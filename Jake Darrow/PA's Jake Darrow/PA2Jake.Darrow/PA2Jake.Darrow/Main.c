#define _CRT_SECURE_NO_WARNINGS // necessary to ignore scanf_s () warnings



#include "PA2header.h"

int main(void) // the starting point for all C programs

{
    // Problem #1 //Total series resistance: series_resistance = R1 + R2 + R3, for 3 resistors. R1, R2, and R3 are integers.
    int R1 = 0, R2 = 0, R3 = 0, result1 = 0;                //create varaibles and give them a value so that they can exist
            //could have been on line above b/c same action just differently named variable
    printf("Enter 3 integers representing \n R1, R2, and R3 \n");     //prompting software user
    scanf("%d%d%d", &R1, &R2, &R3);                                  //reads and stores 3 integer inputs from user

    result1 = series_resistance(R1, R2, R3);

    printf("\n%d", result1); //presents solution


    // Problem numba 2 (:
    double sales_tax_rate = 0.0, item_cost = 0.0, result2 = 0.0; //double means set up float with extra digits available for storage
    printf("Enter sales_tax_rate and item_cost \n ");
    scanf("%lf%lf", &sales_tax_rate, &item_cost); //%lf longfloat

    result2 = total_sales_tax(sales_tax_rate, item_cost);

    printf("Here is your total sales tax value: \n %lf", result2);


    // Problem 3
    double l = 0.0, w = 0.0, h = 0.0, result3 = 0.0;
    printf("\ngimme yo dimensions \n");
    scanf("%lf%lf%lf", &l, &w, &h);

    result3 = volume(l, w, h);

    printf("Presenting your new volume: \n %lf", result3);



    //Problem 4
    int R4 = 0, R5 = 0, R6 = 0;             //set up integer variables
    float result4 = 0.0;        //set up variable with decimal place
    printf("\nEnter 3 integers representing \n R1, R2, and R3 \n");
    scanf("%d%d%d", &R4, &R5, &R6);

    result4 = parallel_resistance(R4, R5, R6);

    printf("%lf", result4);




    //Problem number 5
    int shift_int = 0, result5; //define my variables and give them a value
    char plaintext_character = '\0'; // characters defined with char, gotta give em null \0 or ' ' blank
    printf("Please enter an integer: ");
    scanf("%d", &shift_int);
    printf("Please enter plaintext_character: ");
    scanf(" %c", &plaintext_character); //can't forget the space when calling a character

    result5 = encoded_character(plaintext_character, shift_int); //here's the math

    printf("%d", result5); //displays the value for encoded_character after computation



    //Problem number 6
    double x2 = 0.0, x1 = 0.0, y1 = 0.0, y2 = 0.0, result6 = 0.0;
    printf("Enter x1, x2, y1, y2 \n");
    scanf("%lf%lf%lf%lf", &x1, &x2, &y1, &y2);

    result6 = distance(x1, x2, y1, y2);

    printf("Distance here: %lf \n", result6);



    //Problem 7
    int z = 0, x = 0, a = 0;
    float result7 = 0.0;
    printf("please enter z, x , and a values");
    scanf("%d%d%d", &z, &x, &a);

    result7 = answer(z, x, a);

    printf("y...%lf", result7);



    return 0;

} // end of the main () function