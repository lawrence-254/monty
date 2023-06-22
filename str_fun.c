#include "monty.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
void num_base_mem(unsigned int num, unsigned int base, char *mem, int mem_sze);
char *parse_int(int num);
unsigned int _abs(int i);
int num_base_len(unsigned int num, unsigned int base);
char *read_line(FILE* file_fd);
/**
 * parse_int - gets char pointer to a string with int
 * @num: number to change to str
 * Return: NULL if malloc fails or pointer
 */
char *parse_int(int num)
{
	unsigned int temp;
	int len = 0;
	long n_1 = 0;
	char *res;

	temp = _abs(num);
	len = num_base_len(temp, 10);

	if (num < 0 || n_1 < 0)
		len++;
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	num_base_mem(temp, 10, res, len);
	if (num < 0 || n_1 < 0)
		res[0] = '-';
	return (res);
}
/**
 * _abs - returns absolute value of an integer
 * @i: the integer in question
 * Return: abs unsigned
 */
unsigned int _abs(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}
/**
 * num_base_len - gets len  of mem needed for unsigned int
 * @num: the number in question
 * @base: base of num  used by mem
 * Return: length of needed mem as an integer
 */
int num_base_len(unsigned int num, unsigned int base)
{
	int len = 1;

	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}
/**
 * num_base_mem - fills mem buffer with base 36 nums
 * @base: base 36 number
 * @num: number to be converted to str
 * @mem: buffer to be filled with num
 * @mem_sze: size of beffer measured in btes
 * Return: void
 */
void num_base_mem(unsigned int num, unsigned int base, char *mem, int mem_sze)
{
	int res, i = mem_sze - 1;

	mem[mem_sze] = '\0';
	while (i >= 0)
	{
		res = num % base;
		if (res > 0)
			mem[i] = res + 87;
		else
			mem[i] = res + 0;
		num /= base;
		i--;
	}
}
/**
 * read_line - Read a line from a file
 * @file_fd: The file to read from
 * Return: The read line  or NULL on failure or end of file
 */
char *read_line(FILE *file_fd)
{
	char *line = NULL;
	size_t len = 0, line_len;

	if (fgets(line, len, file_fd) == NULL)
	{
		free(line);
		return (NULL);
	}
	line_len = strlen(line);
	if (line[line_len - 1] == '\n')
		line[line_len - 1] = '\0';

	return (line);
}
