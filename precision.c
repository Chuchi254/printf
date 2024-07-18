#include "main.h"

/**
 * handle_precision - handles the precision for non-custom conversion
 * specifiers
 * @args: list of arguments passed to the _printf function
 * @specifier: character indicating specifier type
 * @buffer: buffer to store the output
 * @buf_index: current index in the buffer
 * @precision: precision for the conversion specifier
 *
 * Return: the number of characters printed
 */

int handle_precision(va_list args, char specifier, char *buffer,
		int *buf_index, int precision)
{
	char temp_buffer[1024];
	int temp_index = 0, num_digits = 0, i;
	unsigned long num = 0, temp;

	if (specifier == 'd' || specifier == 'i')
		num = va_arg(args, int);
	else if (specifier == 'u')
		num = va_arg(args, unsigned int);
	else if (specifier == 'o')
		num = va_arg(args, unsigned int);
	else if (specifier == 'x' || specifier == 'X')
		num = va_arg(args, unsigned int);

	temp = num;
	do {
		num_digits++;
		temp /= 10;
	} while (temp > 0);

	while (precision > num_digits)
	{
		temp_buffer[temp_index++] = '0';
		num_digits++;
	}

	do {
		temp_buffer[temp_index++] = (num % 10) + '0';
		num /= 10;
	} while (num > 0);

	for (i = temp_index - 1; i >= 0; i--)
		buffer[(*buf_index)++] = temp_buffer[i];

	return (temp_index);
}
