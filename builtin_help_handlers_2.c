#include "shell.h"

/**
 * help_env - Display the information on shell by the command _env_
 */
void help_env(void)
{
	char *msg = "env: env\n\tPrints the current environment.\n";

	write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * help_setenv - Display the information on the shell by the command _setenv_
 */
void help_setenv(void)
{
	char *msg = "setenv: setenv [VARIABLE] [VALUE]\n\tInitializes a new";

	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "environment variable, or modifies an existing one.\n\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "\tUpon failure, prints a message to stderr.\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * help_unsetenv - Display the information on shell
 *			- by the command _unsetenv_
 */
void help_unsetenv(void)
{
	char *msg = "unsetenv: unsetenv [VARIABLE]\n\tRemoves an ";

	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "environmental variable.\n\n\tUpon failure, prints a ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "message to stderr.\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * display_help - display help for all builtin commands
 *
 * @cmd: parsed command
 * @st: Status of last command executed
 *
 * Return: Always 0 Success
 */
int display_help(char **cmd, __attribute__((unused))int st)
{
	if (!cmd[1])
		help_all();
	else if (_strcmp(cmd[1], "alias") == 0)
		help_alias();
	else if (_strcmp(cmd[1], "cd") == 0)
		help_cd();
	else if (_strcmp(cmd[1], "exit") == 0)
		help_exit();
	else if (_strcmp(cmd[1], "env") == 0)
		help_env();
	else if (_strcmp(cmd[1], "setenv") == 0)
		help_setenv();
	else if (_strcmp(cmd[1], "unsetenv") == 0)
		help_unsetenv();
	else if (_strcmp(cmd[1], "help") == 0)
		help_help();
	return (0);
}
