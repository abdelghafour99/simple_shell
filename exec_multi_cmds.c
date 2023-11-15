#include "shell.h"
/**
 * exec_multi_cmds - execute multiple commands
 * @prompt: user input
 * @sh_name: program name
 * @cnt: count
 * Return: exit code
 *
 * Made by Noureddine Oubourhim, Abdelghafour Oussi
 */
int exec_multi_cmds(char *prompt, char *sh_name, int cnt)
{
	int num_of_cmds, num_of_words, i, ex_code = 0;
	char **arr_of_cmds, **arr_of_words;

	arr_of_cmds = split_string(prompt, ";", &num_of_cmds);
	if (arr_of_cmds == NULL)
	{
		printf("Error splitting user input\n");
		return (errno);
	}

	for (i = 0; i < num_of_cmds; i++)
	{
		arr_of_words = split_string(arr_of_cmds[i], " \t\r\n", &num_of_words);
		if (arr_of_words == NULL)
		{
			perror("Error splitting command string\n");
			continue;
		}
		if (num_of_words == 0)
		{
			free_words(arr_of_cmds, num_of_cmds);
			free_words(arr_of_words, num_of_cmds);
			return (0);
		}
		if (_strcmp(arr_of_words[0], "exit") == 0)
		{
			free_words(arr_of_cmds, num_of_cmds);
			handle_exit_status(arr_of_words, prompt,
							   sh_name, cnt, num_of_words);
		}
		ex_code = exec_forking(arr_of_words, prompt, sh_name,
							   cnt, num_of_words);
		free_words(arr_of_words, num_of_words);
	}

	free_words(arr_of_cmds, num_of_cmds);
	return (ex_code);
}
