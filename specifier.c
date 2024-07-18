#include "main.h"

/**
 * handle_specifier - handles the conversion specifier with width and precision
 * @args: list of arguments passed to the _printf function
 * @specifier: character indicating the specifier type
 * @buffer: buffer to store the output
 * @buf_index: current index in the buffer
 * @width: width specified in the format string
 * @precision: precision specified in the format string
 *
 * Return: the number of characters printed
 */

int handle_specifier(va_list args, char specifier, char *buffer,
		int *buf_index, int width, int precision)
{
	char temp_buffer[1024];
	int temp_index = 0, count = 0, padding = 0, i, leading_zeros;

	count += dispatch_specifier(args, specifier, temp_buffer, &temp_index);
	leading_zeros = (precision > temp_index) ? precision - temp_index : 0;
	padding = (width > (temp_index + leading_zeros)) ?
		width - (temp_index + leading_zeros) : 0;

	for (i = 0; i < padding; i++)
		buffer[(*buf_index)++] = ' ';

	for (i = 0; i < leading_zeros; i++)
		buffer[(*buf_index)++] = '0';

	for (i = 0; i < temp_index; i++)
		buffer[(*buf_index)++] = temp_buffer[i];

	return (count + (padding > 0 ? padding : 0));
}
