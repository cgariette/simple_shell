#include "shell.h"

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

        	_parse(buffer," ");
	}
	free(buffer);
        return (0);
}
