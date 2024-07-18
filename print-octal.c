#include "main.h"

/**
 * print_octal - prints an unsigned long integer number in octal
 * @num: the unsigned integer to print
 * @buffer: buffer to store the output
 * @buf_index: current index in the buffer
 * @precision: preision for the conversion specifier
 *
 * Return: the number of characters printed
 */

int print_octal(
		unsigned long num, char *buffer, int *buf_index, int precision)
{
	int count = 0, num_digits = 0, i = 0;
	char temp_buffer[22];
	unsigned long temp = num;

	do {
		num_digits++;
		temp /= 8;
	} while (temp > 0);

	while (num_digits < precision)
	{
		buffer[(*buf_index)++] = '0';
		count++;
		num_digits++;
	}

	do {
		temp_buffer[i++] = (num % 8) +  '0';
		num /= 8;
	} while (num > 0);

	while (i > 0)
	{
		buffer[(*buf_index)++] = temp_buffer[--i];
		count++;
	}

	return (count);
}
