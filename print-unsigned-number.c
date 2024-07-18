#include "main.h"

/**
 * print_unsigned_number - prints an unsinged long integer number
 * @num: the unisgned integer to pritn
 * @buffer: buffer to store the output
 * @buf_index: current index in the buffer
 * @precision: precision for the conversion specifier
 *
 * Return: the number of characters printed
 */

int print_unsigned_number(
		unsigned long num, char *buffer, int *buf_index, int precision)
{
	int count = 0, num_digits = 0, i = 0;
	char temp_buffer[20];
	unsigned long temp = num;

	do {
		num_digits++;
		temp /= 10;
	} while (temp > 0);

	while (num_digits < precision)
	{
		buffer[(*buf_index)++] = '0';
		count++;
		num_digits++;
	}

	do {
		temp_buffer[i++] = (num % 10) + '0';
		num /= 10;
	} while (num > 0);

	while (i > 0)
	{
		buffer[(*buf_index)++] = temp_buffer[--i];
		count++;
	}

	return (count);
}
