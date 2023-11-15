#include "shell.h"
/**
 * main - main function
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0
 *
 * Made by Noureddine Oubourhim, Abdelghafour Oussi
 */
int main(int argc, char **argv)
{
	char *input_holder = NULL;
	int exit_code = 0, cmd_count = 0;
	(void)argc;

	signal(SIGINT, handle_signal);

	while (isatty(STDIN_FILENO))
	{
		cmd_count++;
		printf("#cisfun$ ");
		input_holder = read_input();
		if (input_holder == NULL)
		{
			printf("\n");
			return (-1);
		}
		exit_code = exec_multi_cmds(input_holder, argv[0], cmd_count);
		free(input_holder);
		input_holder = NULL;
	}

	while ((input_holder = read_input()) != NULL)
	{
		cmd_count++;
		exit_code = exec_multi_cmds(input_holder, argv[0], cmd_count);
		if (input_holder != NULL)
			free(input_holder);
	}
	input_holder = NULL;
	return (exit_code);
}
