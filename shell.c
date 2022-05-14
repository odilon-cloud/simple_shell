#include "simpleshell.h"

/**
 * main - main function.
 *
 * Return: 0.
 */
int main(void)
{
	int name_cond = 1;
	int sign = 1;
	char *line = NULL;
	char **tokens = NULL;

	signal(SIGINT, sigint_handler);

	while (name_cond)
	{
		write(STDIN_FILENO, "$ ", 2);

		line = reading();
		sign = semicolon(line);
		tokens = cutting(line);
		name_cond = comparing(tokens);

		if (name_cond == 1 && sign == 1)
		{
			name_cond = executing(tokens, line);
		}
		free(line);
		free(tokens);
	}
	return (EXIT_SUCCESS);
}

/**
 * sigint_handler -  Signal Handler function.
 * @sigint: Reset handler to catch SIGINT next time.
 *
 * Return: Nothing.
 */
void sigint_handler(int sigint)
{
	(void)sigint;

	signal(SIGINT, sigint_handler);
	write(STDOUT_FILENO, "\n$ ", 3);
	fflush(stdout);
}
