#include "main.h"

/**
 * handle_length_l - handles the length modifiers l
 * @args: list of arguments passed to the _printf function
 * @buffer: buffer to store the output
 * @specifier: character indicating specifier type
 * @buf_index: current index in the buffer
 * @width: field width for the conversion specifier
 * @precision: precision for the conversion specifier
 * @zero_flag: boolean indicating if the zero flag is specified
 * @left_align: boolean indicating if the - flag is specified
 *
 * Return: the number of characters printed
 */

int handle_length_l(va_list args, char specifier, char *buffer,
		int *buf_index, int width, int precision, bool zero_flag, bool left_align)
{
	char temp_buffer[1024], pad_char;
	int temp_index = 0, count = 0, padding, i;
	unsigned long num;

	num = (specifier == 'd' || specifier == 'i') ? va_arg(args, long) :
		(specifier == 'u') ? va_arg(args, unsigned long) :
		(specifier == 'o') ? va_arg(args, unsigned long) :
		va_arg(args, unsigned long);

	if (specifier == 'd' || specifier == 'i')
		count = print_number(num, temp_buffer, &temp_index, precision);
	else if (specifier == 'u')
		count = print_unsigned_number(num, temp_buffer, &temp_index, precision);
	else if (specifier == 'o')
		count = print_octal(num, temp_buffer, &temp_index, precision);
	else if (specifier == 'x' || specifier == 'X')
		count = print_hex(num, temp_buffer, &temp_index,
				precision, specifier == 'X');

	padding = width - count;
	pad_char = zero_flag ? '0' : ' ';

	if (left_align)
	{
		for (i = 0; i < temp_index; i++)
			buffer[(*buf_index)++] = temp_buffer[i];
		for (i = 0; i < padding; i++)
			buffer[(*buf_index)++] = ' ';
	}
	else
	{
		for (i = 0; i < padding; i++)
			buffer[(*buf_index)++] = pad_char;
		for (i = 0; i < temp_index; i++)
			buffer[(*buf_index)++] = temp_buffer[i];
	}

	return (count + (padding > 0 ? padding : 0));
}
