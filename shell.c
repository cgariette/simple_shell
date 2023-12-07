#include "shell.h"

int main(void)
{
	int argc = 0, count = 0;
	size_t n = 0;
        ssize_t line;
	char *str = NULL, *string = NULL, *token = NULL;
	char *delim = " \n";
	char **argv = NULL;

	while (1)
	{
		_putchar('$');
        	line = getline(&str, &n, stdin);

        	if (line == -1)
        	{
                	perror("Error");
                	free(str);
                	return (-1);
		}
		string = strdup(str);
		token = strtok(str, delim); 

		while(token)
		{
			printf("%s\n", token);
			token = strtok(NULL, delim);
			argc++;
		}

		printf(">>>>> %d \n", argc);

		argv = malloc(sizeof(char *) * argc);
		token = strtok(string, delim);

		while(token)	
		{
			argv[count] = token;
			printf(">>>>> %s \n", argv[count]);
			count++;
			token= strtok(NULL, delim);
		}
		argv[count] = NULL;

	}
	
	free(str), free(string), free(argv);
        return (0);
}
