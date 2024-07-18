#include "main.h"

/**
 * handle_characters - handles the conversion buffers c, s, and %
 * @args: list of arguments passed to the _printf function
 * @specifier: character indicating specifier type
 * @buffer: buffer to store the output
 * @buf_index: current index in the buffer
 *
 * Return: the number of characters printed
 */

int handle_characters(
		va_list args, char specifier, char *buffer, int *buf_index)
{
	char c, *s;
	int count = 0;

	if (specifier == 'c')
	{
		c = va_arg(args, int);
		count += print_char(c, buffer, buf_index);
	}
	else if (specifier == 's')
	{
		s = va_arg(args, char *);
		count += print_string(s, buffer, buf_index);
	}
	else if (specifier == '%')
		count += print_char('%', buffer, buf_index);

	return (count);
}
