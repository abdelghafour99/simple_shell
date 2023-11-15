#include "shell.h"
/**
 * p_the_err- error
 * @cnt: count
 * @sh_name: name
 * @cmd: command
 * @msg: message
 * Return: void
 *
 * Made by Noureddine Oubourhim, Abdelghafour Oussi
 */
void p_the_err(char *cnt, char *sh_name, char *cmd, char *msg)
{
	write(STDERR_FILENO, sh_name, _strlen(sh_name));
	if (cmd != NULL)
	{
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, cnt, _strlen(cnt));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, cmd, _strlen(cmd));
	}
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, msg, _strlen(msg));
}

/**
 * ex_err - error
 * @arr_of_words: array
 * @cntr: count
 * @sh_name: name
 * Return: void
 *
 * Made by Noureddine Oubourhim, Abdelghafour Oussi
 */
void ex_err(char **arr_of_words, int cntr, char *sh_name)
{
	char *err_code = intToString(cntr);

	write(STDOUT_FILENO, sh_name, _strlen(sh_name));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, err_code, _strlen(err_code));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, arr_of_words[0], _strlen(arr_of_words[0]));
	write(STDOUT_FILENO, ": Illegal number: ", 19);
	write(STDOUT_FILENO, arr_of_words[1], _strlen(arr_of_words[1]));
	write(STDOUT_FILENO, "\n", 2);
	free(err_code);
}
