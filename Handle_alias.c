#include "shell.h"
/**
 * save_alias - save alias
 * @alias_name: name
 * @alias_value: value
 * Return: 1
 *
 * Made byNoureddine Oubourhim, Abdelghafour Oussi
 */
int save_alias(const char *alias_name, const char *alias_value)
{
	if (alias_name && alias_value)
	{
		char env_name[MAX_ALIAS_NAME_LENGTH + 7] = "ALIAS_";

		strcat(env_name, alias_name);
		_setenv(env_name, alias_value, 1);
		return (1);
	}
	return (0);
}

/**
 * add_alias - add alias
 * @n: name
 * @v: value
 * @alias_count: alias count
 * @aliases: list of aliases
 * Return: 1
 *
 * Made byNoureddine Oubourhim, Abdelghafour Oussi
 */
int add_alias(const char *n, const char *v, int alias_count, Alias *aliases)
{
	if (alias_count < MAX_ALIASES)
	{
		int i;

		for (i = 0; i < alias_count; i++)
		{
			if (_strcmp(aliases[i].name, n) == 0)
			{
				_strcpy(aliases[i].value, v);
				save_alias(n, v);
				return (1);
			}
		}
		_strcpy(aliases[alias_count].name, n);
		_strcpy(aliases[alias_count].value, v);
		alias_count++;
		save_alias(n, v);
		return (1);
	}
	else if (alias_count >= MAX_ALIASES)
	{
		printf("Maximum number of aliases exceeded.\n");
		return (0);
	}
	return (0);
}

/**
 * delete_alias - delete alias
 * @alias_name: name
 * @alias_count: alias count
 * @aliases: list of aliases
 * Return: 1
 *
 * Made by Noureddine Oubourhim, Abdelghafour Oussi
 */
int delete_alias(const char *alias_name, int alias_count, Alias *aliases)
{
	int i;
	char env_name[MAX_ALIAS_NAME_LENGTH + 7] = "ALIAS_";

	for (i = 0; i < alias_count; i++)
	{
		if (_strcmp(aliases[i].name, alias_name) == 0)
		{
			int j;

			for (j = i; j < alias_count - 1; j++)
			{
				_strcpy(aliases[j].name, aliases[j + 1].name);
				_strcpy(aliases[j].value, aliases[j + 1].value);
			}
			alias_count--;
			strcat(env_name, alias_name);
			_unsetenv(env_name);
			return (1);
		}
	}
	printf("Alias not found.\n");
	return (0);
}

/**
 * unalias_commands - unalias commands
 * @alias_name: name
 * @alias_count: alias count
 * @aliases: list of aliases
 * Return: 1
 *
 * Made by Noureddine Oubourhim, Abdelghafour Oussi
 */
int unalias_commands(const char *alias_name, int alias_count, Alias *aliases)
{
	int i, o;
	char env_name[MAX_ALIAS_NAME_LENGTH + 7] = "ALIAS_";
	const char *name;

	for (i = 0; i < alias_count; i++)
	{
		if (_strcmp(aliases[i].name, alias_name) == 0)
		{
			int j;

			for (j = i; j < alias_count - 1; j++)
			{
				aliases[j] = aliases[j + 1];
			}
			alias_count--;
			_strcat(env_name, alias_name);
			name = env_name;
			o = _unsetenv(name);
			if (o >= 0)
				printf("Alias '%s' has been removed.\n", alias_name);
			return (1);
		}
	}
	printf("Alias '%s' not found.\n", alias_name);
	return (0);
}

/**
 * insert_existing_aliases - insert existing aliases
 * @alias_count: alias count
 * @aliases: list of aliases
 * Return: void
 *
 * Made by Noureddine Oubourhim, Abdelghafour Oussi
 */
void insert_existing_aliases(int alias_count, Alias *aliases)
{
	int i;
	char *alias_name, *alias_value;

	alias_count = 0;
	for (i = 0; environ[i] != NULL; i++)
	{
		char *env_var = environ[i];

		if (strncmp(env_var, "ALIAS_", 6) == 0)
		{
			char *equals_sign = strchr(env_var, '=');

			if (equals_sign != NULL)
			{
				*equals_sign = '\0';
				alias_name = env_var + 6;
				alias_value = equals_sign + 1;

				if (alias_count < MAX_ALIASES)
				{
					_strncpy(aliases[alias_count].name, alias_name, MAX_ALIAS_NAME_LENGTH);
					_strncpy(aliases[alias_count].value, alias_value, MAX_ALIAS_VALUE_LENGTH);
					alias_count++;
				}
				else
				{
					printf("Maximum number of aliases exceeded.\n");
					break;
				}
			}
		}
	}
}
