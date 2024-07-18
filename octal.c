#include "main.h"

/**
 * handle_octal - handles the conversion specifer o for octal
 * @args: list of arguments passed to the _printf function
 * @buffer: buffer to store the output
 * @buf_index: current index in the buffer
 *
 * Return: the number of characters printed
 */

int handle_octal(va_list args, char *buffer, int *buf_index)
{
	unsigned int num = va_arg(args, unsigned int);
	int count = 0;
	char temp_buffer[12];
	int i = 0;

	if (num == 0)
	{
		buffer[(*buf_index)++] = '0';
		return (1);
	}

	while (num > 0)
	{
		temp_buffer[i++] = (num % 8) + '0';
		num /= 8;
	}

	while (i > 0)
	{
		buffer[(*buf_index)++] = temp_buffer[--i];
		count++;
	}

	return (count);
}
