#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char **op_toks = NULL

/**
 * main - gateway into the monty interpreter
 * @argc: argument count
 * @argv: argument vector
 * Return: exitsuccess or exitfailure
 */
int main(int argc, char **argv)
{
	FILE *file_fd = NULL;
	int tmnt  = EXIT_SUCCESS;

	if (argc != 2)
		return (use_err());

	file_fd = fopen(argv[1], 'r');
	if (file_fd == NULL)
		return (fopen_err(argv[1]));
	tmnt = run_monty(file_fd);
	fclose(file_fd);
	return (tmnt);
}
