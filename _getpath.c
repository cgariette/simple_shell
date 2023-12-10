#include "shell.h"

char *get_path(char *cmd)
{
	char *path, path_cpy, *path_token, *file_path;
	int cmd_len, dir_len;

	path = getenv("PATH");

	if (path)
	{
	path_cpy = strdup(path);

	cmd_len = strlen(cmd);

	path_token = strtok(path_cpy, ":");

	while (path)
	
	{
		dir_len = strlen(path_token);

		file_path = malloc(cmd_len + dir_len + 2);

		strcpy(file_path, path_token);
		strcat(file_path, "/");
		strcat(file_path, command);
		strcat(filepath, "\0");
	
	}
