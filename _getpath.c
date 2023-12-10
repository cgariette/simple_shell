#include "shell.h"

char *get_path(char *cmd)
{
	char *path, *path_cpy, *path_token, *file_path;
	int cmd_len, dir_len;
	struct stat buf;

	path = getenv("PATH");
	
	if (path)
	{
	path_cpy = strdup(path);

	cmd_len = strlen(cmd);

	path_token = strtok(path_cpy, ":");

	while (path != NULL)
	{
		dir_len = strlen(path_token);

		file_path = malloc(cmd_len + dir_len + 2);

		strcpy(file_path, path_token);
		strcat(file_path, "/");
		strcat(file_path, cmd);
		strcat(file_path, "\0");
		

		if (stat(file_path, &buf) == 0)
		{
			free(path_cpy);
	
			return (file_path);
		}
		else {
			free(file_path);

			path_token = strtok(NULL, ":");
		}
		}
	free(path_cpy);

	if (stat(cmd, &buf) == 0)
	{
		return (cmd);
	}

	return (NULL);

	}

	return (NULL);
}
