#include "shell.h"

/**
 * run_commands_from_file - Execute commands from a file
 * @filename: The name of the file containing the commands
 * Return: void
 *
 * Made by Noureddine Oubourhim, Abdelghafour Oussi
 */
void run_commands_from_file(char *filename)
{
	FILE *file = fopen(filename, "r");
	char line[MAX_COMMAND_LENGTH];

	if (file == NULL)
	{
		printf("./hsh: 0: Can't open %s\n", filename);
		return;
	}

	while (fgets(line, sizeof(line), file))
	{
		if (line[strlen(line) - 1] == '\n')
			line[strlen(line) - 1] = '\0';
		exec_file(line);
	}

	fclose(file);
}

/**
 * exec_file - Execute a command
 * @command: The command to execute
 * Return: void
 *
 * Made by Noureddine Oubourhim, Abdelghafour Oussi
 */
void exec_file(char *command)
{
	pid_t pid;
	int status;

	if (command[0] == '#')
		return;

	pid = fork();
	if (pid < 0)
	{
		printf("Forking child process failed.\n");
		return;
	}
	else if (pid == 0)
	{
		char *args[MAX_ARGS];

		tokenize_command(command, args);

		if (execvp(args[0], args) == -1)
		{
			printf("./hsh: 0: Can't open %s\n", args[0]);
			exit(EXIT_FAILURE);
		}

		exit(EXIT_SUCCESS);
	}
	else
	{
		waitpid(pid, &status, 0);

		if (WIFEXITED(status))
		{
			int exit_status = WEXITSTATUS(status);

			printf("Child process exited with status: %d\n", exit_status);
			fflush(stdout);
		}
	}
}

/**
 * tokenize_command - Tokenizes a command
 * @command: The command to tokenize
 * @args: The array to store the tokens
 * Return: The number of tokens
 *
 * Made by Noureddine Oubourhim, Abdelghafour Oussi
 */
int tokenize_command(char *command, char *args[])
{
	int i = 0;
	char *token = strtok(command, " ");

	while (token != NULL && i < MAX_ARGS - 1)
	{
		args[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;

	return (i);
}
