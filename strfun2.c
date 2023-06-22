#include "monty.h"
#include <stdlib.h>
int is_delim(char ch, char *delims);
char **strtow(char *str, char *delims);
int get_word_count(char *str, char *delims);
char *get_next_word(char *str, char *delims);
int get_word_length(char *str, char *delims);
/**
 * strtow - changes string to word
 * @str: the string to be changed to word
 * @delims: delimitors to be used in word
 * Return: word
 */
char **strtow(char *str, char *delims)
{
	char **words = NULL;
	int wordLen, wordCnt, n, i = 0;

	if (!*str || str ==NULL)
		return (NULL);
	wordCnt = get_word_count(str, delims);
	if(wordCnt == 0)
		return (NULL);
	words = malloc((wordCnt + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	while (i < wordCnt)
	{
		wordLen = get_word_length(str, delims);
		if (is_delim(str, delims))
			str = get_next_word(str, delims);
		words[i] = malloc((wordLen + 1) * sizeof(char *));
		if (words[i] == NULL)
		{
			while (i >= 0)
			{
				i--;
				free(words[i]);
			}
			free(words);
			return (NULL);
		}
		n = 0;
		while (n < wordLen)
		{
			words[i][n] = *(str + n);
			n++;
		}
		words[i][n] = '\0';
		str = get_next_word(str, delims);
		i++;
	}
	words[i] = NULL;
	return (words);
}
/**
 * is_delim - checks if there is a delimeter character
 * @ch: chararater to check
 * @delims: pointer to array of delimiters
 * Return: 1 or 0
 */
int is_delim(char ch, char *delims)
{
	int i = 0;

	while (delims[i])
	{
		if (delims[i] == ch)
			return (1);
		i++;
	}
	return (0);
}
/**
 * get_word_length - finds length of word in str
 * @str: string to calculate word len from
 * @delims: delimitors to be used in word
 * Return: wordlen
 */
int get_word_length(char *str, char *delims)
{
	int count = 0, res = 1, i = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], delims))
			res = 1;
		else if (res)
			count++;
		if (count > 0 && is_delim(str[i], delims))
			break;
		i++;
	}
	return (count);
}
/**
 * get_word_count - counts the words in a string
 * @str: string in question
 * @delims: delimitors to be used in word
 * Return: number of words in the string
 */
int get_word_count(char *str, char *delims)
{
	int count = 0, res = 1, i = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], delims))
			res = 1;
		else if (res)
		{
			res = 0;
			count++;
		}
		i++;
	}
	return (count);
}
/**
 * get_next_word - returns next word in a string
 * @str: string in question
 * delims: delimitors to be used in word
 * Return: pointer to the found word
 */
char *get_next_word(char *str, char *delims)
{
	int i = 0, res = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], delims))
			res = 1;
		else if (res)
			break;
		i++;
	}
	return (str + i);
}
