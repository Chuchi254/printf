#include "main.h"

/**
 * handle_integers - handles the conversion buffers d and i
 * @args: list of arguments passed to the _printf function
 * @buffer: buffer to store the output
 * @buf_index: current index in the buffer
 *
 * Return: the number of characters printed
 */

int handle_integers(va_list args, char *buffer, int *buf_index)
{
	int count = 0, num;

	num = va_arg(args, int);
	count += print_number(num, buffer, buf_index, 0);
	return (count);
}
