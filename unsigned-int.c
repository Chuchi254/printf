#include "main.h"

/**
 * handle_unsigned_int - handles the conversion specifier u for
 * unsigned integers
 * @args: list of arguments passed to the _printf function
 * @buffer: buffer to store the output
 * @buf_index: current index in the buffer
 *
 * Return: the number of character  printed
 */

int handle_unsigned_int(va_list args, char *buffer, int *buf_index)
{
	unsigned int num = va_arg(args, unsigned int);
	int count = 0;
	char temp_buffer[10];
	int i = 0;

	if (num == 0)
	{
		buffer[(*buf_index)++] = '0';
		return (1);
	}

	while (num > 0)
	{
		temp_buffer[i++] = (num % 10) + '0';
		num /= 10;
	}

	while (i > 0)
	{
		buffer[(*buf_index)++] = temp_buffer[--i];
		count++;
	}

	return (count);
}
