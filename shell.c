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
	char *name = "exit\n";
	int compare;

	while (1)
	{
		write(1, "shell$ ", 7);
		line = getline(&str, &n, stdin);
		compare = strcmp(str, name);

		if (line == -1 || compare == 0)
		{
			perror("Exiting");
			free(str);
			return (-1);
		}
		else
		{
			argv = malloc(sizeof(char *) * argc);
			_token(str, argv, argc);
			_getpath(argc, argv);
			argc = 0;
			free(argv);
		}
	}
	return (0);
}
