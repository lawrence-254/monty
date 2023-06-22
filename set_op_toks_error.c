#include "monty.h"
/**
 * set_op_tok_error - changes last element of op_toks to error code
 * @error_code: the error code in question
 */
void set_op_tok_error(int error_code)
{
	int len = 0, i = 0;
	char *e_str = NULL, **n_toks = NULL;

	len = get_tok_arr_len();
	n_toks = malloc(sizeof(char *) * (len +2));
	if (!op_toks)
	{
		malloc_err();
		return;
	}
	while (i < len)
	{
		n_toks[i] = op_toks[i];
		i++;
	}
	e_str = get_int(error_code);
	if (!e_str)
	{
		free(n_toks);
		malloc_err();
		return;
	}
	n_toks[i++] = e_str;
	n_toks[i] = NULL;
	free(op_toks);
	op_toks = n_toks;
}
