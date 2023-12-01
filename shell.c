#include "shell.h"

/**
 * _prompt - prints a prompt
 *
 */
void _prompt(void)
{
	size_t n = 10;
	char * buffer = NULL;
	ssize_t line;

	_putchar('$');
	line = getline(&buffer, &n, stdin);

	if (line == -1)
	{
		perror("Error");
		free(buffer);
		exit(EXIT_FAILURE);
	}

	free (buffer);

}

void _parse(char *str, char **args)
{
	char *token;
	int count;

	token = strtok(str, " "); 

	while(token)
	{
		args[count++] = token;
		printf("%s\n", token);
		token = strtok(NULL, " ");
	}
	args[count] = NULL;
}


int main()
{
	char *args[50];

	while (1)
	{
		_prompt();
		_parse("simple shell", args);
	}
	return (0);
}
