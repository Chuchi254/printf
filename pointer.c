#include "main.h"

/**
 * handle_pointer - handles the conversion specifier p for pointer
 * @args: list of arguments passed to the _printf function
 * @buffer: buffer to store the output
 * @buf_index: current index in the buffer
 *
 * Return: the number of characters printed
 */

int handle_pointer(va_list args, char *buffer, int *buf_index)
{
	unsigned long ptr = (unsigned long)va_arg(args, void *);
	int count = 0, digit;
	char temp_buffer[16];
	int i = 0;

	if (ptr == 0)
	{
		buffer[(*buf_index)++] = '(';
		buffer[(*buf_index)++] = 'n';
		buffer[(*buf_index)++] = 'i';
		buffer[(*buf_index)++] = 'l';
		buffer[(*buf_index)++] = ')';
		return (5);
	}

	buffer[(*buf_index)++] = '0';
	buffer[(*buf_index)++] = 'x';
	count += 2;

	while (ptr > 0)
	{
		digit = ptr % 16;
		if (digit < 10)
			temp_buffer[i++] = digit + '0';
		else
			temp_buffer[i++] = digit - 10 + 'a';
		ptr /= 16;
	}

	while (i > 0)
	{
		buffer[(*buf_index)++] = temp_buffer[--i];
		count++;
	}

	return (count);
}
