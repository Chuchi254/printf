#include "main.h"
#include <string.h>

/**
 * handle_reversed - handles the custom conversion specifier r
 * @args: list of arguments passed to the _printf function
 * @buffer: buffer to store the output
 * @buf_index: current index in the buffer
 *
 * Return: the number of characters printed
 */

int handle_reversed(va_list args, char *buffer, int *buf_index)
{
	char *str = va_arg(args, char *);
	int len, i;

	if (str == NULL)
		str = "(null)";

	len = strlen(str);
	for (i = len - 1; i >= 0; i--)
		buffer[(*buf_index)++] = str[i];

	return (len);
}
