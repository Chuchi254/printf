#include "main.h"

/**
 * handle_hex_upper - handles the conversion specifier X for hexadecimal
 * (uppercase)
 * @args: list of arguments passed to the _printf function
 * @buffer: buffer to store the output
 * @buf_index: current index in the buffer
 *
 * Return: the number of chracters pritned
 */

int handle_hex_upper(va_list args, char *buffer, int *buf_index)
{
	unsigned int num = va_arg(args, unsigned int);
	int count = 0, digit;
	char temp_buffer[8];
	int i = 0;

	if (num == 0)
	{
		buffer[(*buf_index)++] = '0';
		return (1);
	}

	while (num > 0)
	{
		digit = num % 16;
		if (digit < 10)
			temp_buffer[i++] = digit + '0';
		else
			temp_buffer[i++] = digit - 10 + 'A';
		num /= 16;
	}

	while (i > 0)
	{
		buffer[(*buf_index)++] = temp_buffer[--i];
		count++;
	}

	return (count);
}
