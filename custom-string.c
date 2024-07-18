#include "main.h"

/**
 * is_non_printable - checks if a character is non-printable
 * @c: the character to check
 *
 * Return: 1 if non-printable, 0 otherwise
 */

int is_non_printable(char c)
{
	return ((c > 0 && c < 32) || (c >= 127));
}

/**
 * handle_custom_string - handles the custom conversion specifier S
 * @args: list of arguments passed to the _printf function
 * @buffer: buffer to store the output
 * @buf_index: current index in the buffer
 *
 * Return: the number of characters printed
 */

int handle_custom_string(va_list args, char *buffer, int *buf_index)
{
	char *s = va_arg(args, char *);
	int count = 0;

	if (s == NULL)
		s = "(null)";

	while (*s)
	{
		if (is_non_printable(*s))
		{
			buffer[(*buf_index)++] = '\\';
			buffer[(*buf_index)++] = 'x';
			count += 2;

			buffer[(*buf_index)++] = ((*s >> 4) & 0xF) + '0';
			if (buffer[*buf_index - 1] > '9')
				buffer[*buf_index - 1] += 7;
			buffer[(*buf_index)++] = (*s & 0xF) + '0';
			if (buffer[*buf_index - 1] > '9')
				buffer[*buf_index - 1] += 7;
			count += 2;
		}
		else
		{
			buffer[(*buf_index)++] = *s;
			count++;
		}
		s++;
	}

	return (count);
}
