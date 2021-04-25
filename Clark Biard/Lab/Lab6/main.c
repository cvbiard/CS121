#include "header.h"

int main(void)
{
	int sum = 0;
	int prime = 0;
	int digit_sum = 0;
	int fact = 0;
	int fibi = 0;
	FILE* input = fopen("input.txt", "r");

	//problem 1
	sum = read_ints(input);
	printf("Sum: %d\n", sum);
	prime = is_prime(sum);
	printf("Is prime? %d.\n", prime);
	digit_sum = sum_digits(sum);
	printf("Sum of digits is %d\n", digit_sum);
	prime = is_prime(digit_sum);
	printf("Is the digit sum prime? %d\n", prime);

	//problem 2
	factorial();

	//problem 3
	fibi = fib(10);
	printf("Number is %d.\n", fibi);
	//problem 4
	guesser();
	return 0;
}