#include "shell.h"

/**
 * _prompt - prints a prompt
 *
 */
int _prompt(void)
{
	size_t n = 0;
	char * buffer = NULL;
	ssize_t line;

	_putchar('$');
	line = getline(&buffer, &n, stdin);

	if (line == -1)
	{
		perror("Error");
		free(buffer);
		return (-1);
	}

	free (buffer);
	return (line);
}

void _parse(char *str, char *delim)
{
	char *token;
	int count;
	char *string = malloc(sizeof(char) * strlen(str));
	
	strcpy(string, str);
	token = strtok(string, delim); 

	while(token)
	{
		printf("%s\n", token);
		token = strtok(NULL, delim);
	}
}


int main(int argc, char *argv[])
{
	/*char *args[50];*/
	int i;

	while (1)
	{
		_prompt();
		while(argv[i] != NULL)
		{
			_parse(argv[i], " ");
			i++;
		}
	}
	return (0);
}
