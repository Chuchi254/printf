#include "main.h"

/**
 * handle_field_width - handles the field width for non-custom
 * conversion specifiers
 * @args: list of arguments passed to the _printf function
 * @specifier: character indicating the specifier type
 * @buffer: buffer to store the output
 * @buf_index: current index in the buffer
 * @width: field width for the conversion specifier
 *
 * Return: the number of characters pritned
 */

int handle_field_width(
		va_list args, char specifier, char *buffer, int *buf_index, int width)
{
	char temp_buffer[1024];
	int temp_index = 0;
	int count = 0, padding = 0, i, precision = 0;

	if (specifier == '.')
	{
		precision = va_arg(args, int);
		specifier = (char)va_arg(args, int);
	}

	count += handle_precision(args, specifier, temp_buffer,
			&temp_index, precision);

	padding = width - count;

	for (i = 0; i < padding; i++)
		buffer[(*buf_index)++] = ' ';
	for (i = 0; i < temp_index; i++)
		buffer[(*buf_index)++] = temp_buffer[i];

	return (count + (padding > 0 ? padding : 0));
}
