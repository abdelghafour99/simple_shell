#include "shell.h"

/**
 * handle_signal - handles signal
 * @sig: signal
 * Return: void
 *
 * Made by Noureddine Oubourhim, Abdelghafour Oussi
 */
void handle_signal(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n#cisfun$ ", 4);
}
