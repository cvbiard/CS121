/*
	Description: This program prompts the user for 
	credits possible in 3 classes, the corresponding grade point
	earned each of the 3 classes, computes the GPA, and
	displays GPA to the screen.

	History: 9/14 - Implemented read_credits () and 
	                read_gp (). Learned how to programmatically
					open files and read from them!
	         9/11 - Implemented compute_gpa (). Reorganized
	                code into 3 files. 
	         9/9 - Implemented user defined function called
	               get_credits ()!
*/

//#include <stdio.h>
#include "gpa.h"
//#include "gpa.c" - don't ever include a .c file!!!!!!

int main(void)
{
	// local variables to main () - can't be accessed
	// outside of main ()
	int credits1 = 0, credits2 = 0, credits3 = 0, 
		sum_credits = 0;
	double gp1 = 0.0, 
		gp2 = 0.0, 
		gp3 = 0.0, 
		weighted_gp = 0.0,
		gpa = 0.0;

	FILE *infile = NULL;

	infile = fopen("classData.txt", "r");

	//// 1. Prompt the user for the credits for class 1
	//printf("Enter credits possible for class 1: ");
	//// 2. Get the credits for class 1 from the user
	//scanf("%d", &credits1);
	//credits1 = get_credits(1); // call our user defined function!
	credits1 = read_credits(infile);
	printf("credits 1: %d\n", credits1);
	gp1 = read_gp(infile);
	printf("gp1: %.2lf\n", gp1);
	// 3. Prompt the user for the grade point for class 1
	//printf("Enter grade point for class 1: ");
	//// 4. Get the grade point earned from the user for class 1
	//scanf("%lf", &gp1);

	// 5. Prompt the user for the credits for class 2
	//printf("Enter credits possible for class 2: ");
	//// 6. Get the credits for class 2 from the user
	//scanf("%d", &credits2);
	//credits2 = get_credits(2);
	credits2 = read_credits(infile);
	printf("credits 2: %d\n", credits2);
	// 7. Prompt the user for the grade point for class 2
	//printf("Enter grade point for class 2: ");
	//// 8. Get the grade point earned from the user for class 2
	//scanf("%lf", &gp2);
	gp2 = read_gp(infile);
	printf("gp2: %.2lf\n", gp2);

	// 9. Prompt the user for the credits for class 3
	//printf("Enter credits possible for class 3: ");
	//// 10. Get the credits for class 3 from the user
	//scanf("%d", &credits3);
	//credits3 = get_credits(3);
	credits3 = read_credits(infile);
	printf("credits 3: %d\n", credits3);
	// 11. Prompt the user for the grade point for class 3
	//printf("Enter grade point for class 3: ");
	//// 12. Get the grade point earned from the user for class 3
	//scanf("%lf", &gp3);
	gp3 = read_gp(infile);
	printf("gp3: %.2lf\n", gp3);

	// 13. Compute the weighted gps
	weighted_gp = (gp1 * credits1) + (gp2 * credits2) +
		(gp3 * credits3);

	// 14. Sum up the credits earned
	sum_credits = credits1 + credits2 + credits3;

	// 15. Compute the GPA
	//gpa = weighted_gp / sum_credits;
	gpa = compute_gpa(weighted_gp, sum_credits);

	// 16. Display the GPA to the screen
	printf("GPA: %.2lf\n", gpa);

	return 0;
} // end of main ()

