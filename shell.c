#include "shell.h"

/**
 * main - get the prompt and executes command
 * Return: 0 if successful
 */

int main(void)
{
	int argc = 0;
	size_t n = 0;
	ssize_t line;
	char *str = NULL;
	char **argv = NULL;

	while (1)
	{
		write(1, "shell$ ", 7);
		line = getline(&str, &n, stdin);

		if (line == -1)
		{
			perror("Error");
			free(str);
			return (-1);
		}

		argv = malloc(sizeof(char *) * argc);
		_token(str, argv, argc);
		_getpath(argc, argv);
		argc = 0;
		free(argv);
	}
	return (0);
}
