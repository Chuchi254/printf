#include "main.h"

/**
 * handle_binary - handles the conversion specifier b for binary.
 * @args: list of arguments passed to the _printf function
 * @buffer: buffer to store the output
 * @buf_index: current index in the buffer
 *
 * Return: the number of characters printed
 */

int handle_binary(va_list args, char *buffer, int *buf_index)
{
	int count = 0;
	unsigned int num = va_arg(args, unsigned int);
	char temp_buffer[32];
	int i = 0;

	if (num == 0)
	{
		buffer[(*buf_index)++] = '0';
		return (1);
	}

	while (num > 0)
	{
		temp_buffer[i++] = (num % 2) + '0';
		num /= 2;
	}

	while (i > 0)
	{
		buffer[(*buf_index)++] = temp_buffer[--i];
		count++;
	}

	return (count);
}
