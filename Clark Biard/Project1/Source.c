#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

double calculate_grade_point(char grade)
{
		switch (grade) {
		case 'A':
			return 4.0;
		case 'B':
			return 3.0;
		case 'C':
			return 2.0;
		case 'D':
			return 1.0;
		case 'F':
			return 0.0;
		default:
			printf("Invalid grade\n");
		}
}

int sum_squares(int n)
{
	int sum = 0;
	if (n >= 1)
	{

		for (int i = 0; i <= n; i++)
		{
			sum = sum + pow(i, 2);
		}
		return sum;
	}
	else
	{
		printf("Please make sure the number is 1 or greater, returning 0");
		return 0;
	}
}

int is_reverse(char str[], char str2[])
{
	int strl1 = strlen(str), strl2 = strlen(str2), front, back;
	printf("String lengths are %d and %d\n", strl1, strl2);

	if (strl1 != strl2)
	{
		printf("String lengths are not equal\n");
		return 0;
	}
	
	for (int i = 0; i < strl1; i++)
	{
		if ((int)str[i] >= 65 && (int)str[i] <= 90)
		{
			str[i] = (int)str[i] + 32;
		}
	}
	for (int i = 0; i < strl1; i++)
	{
		if ((int)str2[i] >= 65 && (int)str2[i] <= 90)
		{
			str2[i] = (int)str2[i] + 32;
		}
	}

	for (int i = 0; i < strl1; i++)
	{
		front = i;
		back = strl1 - (i + 1);
		printf("Comparing %c to %c\n", str[i], str2[back]);
		printf("Front is %d and back is %d\n", front, back);

		if (str[i] != str2[back])
		{
			printf("%c is not equal to %c\n", str[i], str2[back]);
			return 0;
		}
	}
	return 1;
}

int my_str_cpy_variant(char src[], char dest[])
{
	int strl1 = strlen(src), strl2 = strlen(dest), count = 0;
	printf("Length is %d\n", strl1);
	if (strl2 < (strl1 / 2)+1)
	{
		printf("Destination array is too small\n");
		return 0;
	}
	for (int i = 0; i <= strl1; i ++)
	{
		printf("looking at %c\n", src[i]);
		if (src[i] == '\0')
		{
			printf("encountered null, returning 0\n");
			dest[count] = '\0';
			return 0;
		}
		if (src[i] % 2 == 1)
		{
			dest[count] = src[i];
			count = count + 1;
		}
		printf("Count is %d\n", count);
	}
	printf("Got to the end, returning 1\n");
	return 1;
}

int is_anagram(char *str1, char *str2, int *iarr1, int *iarr2)
{
	int index1 = 0, index2 = 0, length1 = strlen(str1), length2 = strlen(str2);
	printf("strings are %s and %s\n", str1, str2);

	for (int i = 0; i < length1; i++)
	{
		if ((int)str1[i] >= 65 && (int)str1[i] <= 90)
		{
			str1[i] = (int)str1[i] + 32;
		}
	}
	for (int i = 0; i < length2; i++)
	{
		if ((int)str2[i] >= 65 && (int)str2[i] <= 90)
		{
			str2[i] = (int)str2[i] + 32;
		}
	}

	for (int i = 0; i < length1; i++)
	{
		index1 = (int)str1[i]-97;
		if (str1[i] != '\0')
		{
			printf("Adding one to the %d position of the table\n", str1[i]);
			iarr1[index1]++;
		}
		
	}
	for (int i = 0; i < length2; i++)
	{
		index2 = (int)str2[i]-97;
		if (str2[i] != '\0')
		{
			printf("Adding one to the %d position of the table\n", str2[i]);
			iarr2[index2]++;
		}
	}

	for (int i = 0; i < 26; i++)
	{
		if (iarr1[i] != iarr2[i])
		{
			printf("Strings are not anagrams\n");
			printf("%d is not %d", iarr1[i], iarr2[i]);
			return 0;
		}
	}
	printf("Strings are anagrams\n");
	return 1;
}

int main(void)
{
	char enter = '\0';
	double calc = 0;
	
	/*
	int yomama[5] = { 1,2,3,4,5 };
	int* test = yomama;
	printf("%d\n", test[2]);
	test = (yomama + 2);
	printf("%d\n", *test);*/
	//int cost;
	//int* cost_ptr;
	//cost_ptr = &cost;                          //assign pointer to cost
	//cost = 100;                                //intialize cost with a value
	//printf("\nDirect Access: %d", cost);
	//cost = 0;                                  //reset the value
	//*cost_ptr = 100;
	//printf("\nIndirect Access: %d", *cost_ptr);
	//printf("\nDirect Access: %d", cost);
	////some code here
	//printf("enter a letter grade");
	//scanf("%c%*c", &enter);
	//calc = calculate_grade_point(enter);
	//printf("number %lf", calc);

	//char test[] = "Heymanwhatsup";
	//char tset[] = { '\0', '\0', '\0', '\0', '\0' };

	//my_str_cpy_variant(test, tset);
	//printf("%s\n", test);
	//printf("%s\n", tset);

	char test[5] = { 't', 'e', 'x-', 't', '\0' };
	char tset[5] = { 't', 'e', 't', 's', '\0' };
	int iarr1[26] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int iarr2[26] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

	char* ptest1, * ptest2, * parr1, * parr2;
	ptest1 = test;
	ptest2 = tset;
	parr1 = iarr1;
	parr2 = iarr2;

	is_anagram(ptest1, ptest2, parr1, parr2);

	//printf("%d", is_reverse(test, tset));


	return 0;                                  //1

	/*char vehicle[20] = "porsche";
	char my_candy[5] = "twix";

	int length = 0, comp = 0;


	length = strlen(vehicle);
	comp = strcmp("ford", vehicle);
	printf("%d\n", length);
	printf("%c\n", my_candy[4]);
	printf("%d\n", comp);
	strncpy(my_candy, vehicle, 2);
	printf("%s\n", my_candy);
	strcat(vehicle, &my_candy[2]);
	printf("%c\n", vehicle[3]);*/

	//int sum = 0, next = 1, bound = 15;
	//while (next <= bound)
	//{
	//	sum += next;
	//	next += 2;
	//	printf("Sum: %d\n", sum);
	//	printf("Next: %d\n", next);
	//}
	//sum = 0;

	//for (int i = 1; i <= 15; i = i + 2)
	//{
	//	sum += i;
	//	printf("i sum: %d\n", sum);
	//}
	return 0;
}