#include "shell.h"
/**
 * cmd_execve - execute command
 * @cmd: command
 * @arr_words: array of words
 * Return: void
 *
 * Made by Noureddine Oubourhim, Abdelghafour Oussi
 */
void cmd_execve(char *cmd, char **arr_words)
{
	if (execvp(cmd, arr_words) == -1)
	{
		perror("Error executing command");
		exit(100);
	}
}

/**
 * wait_child_process - wait for a child process
 * @pid: pid
 * @status: status
 * Return: void
 *
 * Made by Noureddine Oubourhim, Abdelghafour Oussi
 */
void wait_child_process(pid_t pid, int *status)
{
	if (waitpid(pid, status, 0) == -1)
	{
		perror("Error while waiting for child process");
		return;
	}
}
