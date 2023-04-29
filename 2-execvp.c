#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stting.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGS 64

/**
 * main main - returns command argument
 * Return: Always 0
 * Description: main main a function that returns command argument
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];

	char "args[MAX_ARGS];

	while (1)
	{
		printf("$");
		fflush(stdout);

	if (fgets(command,MAX_COMMAND_LENGTH, stdin) == NULL)
	{
		break;

	}

	command[strcspn(command, "\n")] = '\0';

	int num_args = 0;
	char *token = strtok(command, " ");
	while (token != NULL && num_args < MAX_ARGS - 1)
	{
		args[num_args++] = token;
		token = strtok(NULL, " ");
	}
	args[num_args] = NULL;

	if (execvp(args[0], args) == -1)
	{
		printf("Error : command not found\n");
	}

	return (0);
}
