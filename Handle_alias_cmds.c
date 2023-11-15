#include "shell.h"

/**
 * handle_alias_cmds - handle alias commands
 * @args: array of words
 * @i: index
 * @alias_count: alias count
 * @aliases: list of aliases
 * Return: void
 *
 * Made by Noureddine Oubourhim, Abdelghafour Oussi
 */
void handle_alias_cmds(char **args, int *i, int alias_count, Alias *aliases)
{
	while (args[*i] != NULL)
	{
		const char *arg = args[*i];
		const char *equals_sign = strchr(arg, '=');

		if (equals_sign)
		{
			char alias_name[MAX_ALIAS_NAME_LENGTH];
			char alias_value[MAX_ALIAS_VALUE_LENGTH];

			strncpy(alias_name, arg, equals_sign - arg);
			alias_name[equals_sign - arg] = '\0';
			strcpy(alias_value, equals_sign + 1);

			if (add_alias(alias_name, alias_value, alias_count, aliases) == 0)
				return;
		}
		else
		{
			const char *alias_name = args[*i];
			const char *alias_value = get_alias(alias_name, alias_count, aliases);

			if (alias_value != NULL)
				printf("%s=%s\n", alias_name, alias_value);
			else
				printf("Alias '%s' not found.\n", alias_name);
		}
		(*i)++;
	}
}
