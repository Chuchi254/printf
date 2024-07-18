#include "main.h"

/**
 * handle_length_h - handles the length modifiers h
 * @args: list of arguments passed to the _printf function
 * @specifier: character indicating specifier type
 * @buffer: buffer to store the output
 * @buf_index: current index in the buffer
 * @width: field width for the conversion buffer
 * @precision: precision for the conversion buffer
 * @zero_flag: boolean indicating if the zero flag is buffered
 * @left_align: boolean indicating if the - flag is buffered
 *
 * Return: the number of characters printed
 */

int handle_length_h(va_list args, char specifier, char *buffer,
		int *buf_index, int width, int precision, bool zero_flag, bool left_align)
{
	int count = 0, temp_index = 0, i = 0, padding;
	char temp_buffer[1024], pad_char;
	unsigned short num;

	num = (specifier == 'd' || specifier == 'i') ? (short)va_arg(args, int) :
		(specifier == 'u') ? (unsigned short)va_arg(args, int) :
		(specifier == 'o') ? (unsigned short)va_arg(args, int) :
		(unsigned short)va_arg(args, int);

	if (specifier == 'd' || specifier == 'i')
		count = print_number(num, temp_buffer, &temp_index, precision);
	else if (specifier == 'u')
		count = print_unsigned_number(num, temp_buffer, &temp_index, precision);
	else if (specifier == 'o')
		count = print_octal(num, temp_buffer, &temp_index, precision);
	else if (specifier == 'x' || specifier == 'X')
		count = print_hex(num, temp_buffer, &temp_index, precision,
				specifier == 'X');
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
