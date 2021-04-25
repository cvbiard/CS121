#include "header.h"

int read_ints(FILE* input)
{
	int sum = 0;
	int current = 0;
		
	while (feof(input) != 1)
	{
		fscanf(input, "%d", &current);
		sum = sum + current;
	}
	fclose(input);
	return sum;
}
int is_prime(int number)
{
	for (int i = 2; i < number; i++)
	{
		if (number % i == 0 && i != number)
		{
			return 0;
		}
	}
	return 1;
}
int sum_digits(int number)
{
	int sum = 0;
	int current = number;

	while(current > 0)
	{
		sum = sum + (current % 10);
		current = (current / 10);
	}
	return sum;
}
void factorial(void)
{
	int number = 0;
	int index = 0;

	printf("Please enter a positive integer.\n");
	scanf("%d", &number);
	while (number < 0)
	{
		printf("Please enter a positive integer.\n");
		scanf("%d", &number);
	}

	index = number;

	if (number == 1 || number == 0)
	{
		printf("The factorial of %d is 1.\n", number);
	}

	for (int i = 1; i < number - 1; i++)
	{
		index = index*(number - i);
	}

	printf("The factorial of %d is %d.\n", number, index);

}
int fib(int num)
{
	if (num <= 1)
	{
		return num;
	}
	return fib(num - 1) + fib(num - 2);
}
void guesser(void)
{
	int guess = 0;
	srand(time(0));
	int randnumber = ((rand()) % 200) - 100;

	while (guess != randnumber)
	{
		printf("Guess a number!\n");
		scanf("%d", &guess);

		while (guess > 100 || guess < -100)
		{
			printf("Guess a number!\n");
			scanf("%d", &guess);
		}

		if (guess < randnumber)
		{
			printf("Too low, try again!.\n");
		}
		else if (guess > randnumber)
		{
			printf("Too high, try again!.\n");
		}
	}
}