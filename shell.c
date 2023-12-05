#include "shell.h"

void _parse(char *str, char *delim)
{
	char *token;
	int count = 0;
	char *string = malloc(sizeof(char) * strlen(str));
	char args[];
	int i = 0;

	strcpy(string, str);
	token = strtok(string, delim); 

	while(token)
	{
		count++;
		printf("%s\n", token);
		token = strtok(NULL, delim);
	}
	count++;

	args = malloc(sizeof(char)* count);

	while(token)
	{
		args[i] = malloc(sizeof(char)* strlen(token));
		strcpy(args[i], token);
		i++;

		token= strtok(NULL, delim);
	}
	args[i] = NULL;

}


int main(int argc, char **argv[])
{

	size_t n = 0;
        char * buffer = NULL;
        ssize_t line;

	while (1)
	{
		_putchar('$');
        	line = getline(&buffer, &n, stdin);

        	if (line == -1)
        	{
                	perror("Error");
                	free(buffer);
                	exit(EXIT_FAILURE);
        	}

        	_parse(buffer," \n");
	}
	free(buffer);
        return (0);
}
