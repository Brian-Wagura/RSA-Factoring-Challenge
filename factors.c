#include <stdio.h>

/**
 * factorize - Factorize
 * @num: number to factorize
 *
 * Return: void
 */

void factorize(int num)
{
	int i;

	for (i = 2; i <= num / 2; ++i)
	{
		if (num % i == 0)
		{
			printf("%d=%d*%d\n", num, i, num / i);
			return;
		}
	}
	printf("%d=%d*%d\n", num, 1, num);
}

/**
 * main - Entry point
 * @argc: number of cmd arguments
 * @argv: array of cmd arguments
 *
 * Return: A product of two smaller numbers
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		return (1);
	}

	FILE *file = fopen(argv[1], "r");

	if (file == NULL)
	{
		perror("Error opening file");
		return (1);
	}

	int num;

	while (fscanf(file, "%d", &num) == 1)
	{
		factorize(num);
	}

	fclose(file);
	return (0);
}
