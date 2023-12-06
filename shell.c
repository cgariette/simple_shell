#include "shell.h"

int main(int argc, char **argv)
{
	size_t n = 0;
	char *token, *str, *buffer = NULL;
	char *string = malloc(sizeof(char) * strlen(str));
	int i = 0, count = 0;
        ssize_t line;
	char *delim = " \n";
	
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
	strcpy(string, str);
	token = strtok(string, delim); 

	while(token)
	{
		count++;
		token = strtok(NULL, delim);
	}
	count++;

	printf(">>>>> %d \n", count);

	argv = malloc(sizeof(char *)* count);

	while(token)	
	{
		argv[i] = malloc(sizeof(char)* strlen(token));
		strcpy(argv[i], token);
		i++;
		printf(">>>>> %s \n", argv[i]);
		token= strtok(NULL, delim);
	}
	argv[i] = NULL;

	}
	free(buffer);
        return (0);
}
