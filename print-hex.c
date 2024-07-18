#include "main.h"

/**
 * print_hex - pritns an unsigned long integer number in hexadecimal
 * @num: the unsigned integer to pritn
 * @buffer: buffer to store the output
 * @buf_index: current index in the buffer
 * @precision: precision for the conversion specifier
 * @uppercase: whether to print in uppercase
 *
 * Return: the number of characters printed
 */

int print_hex(unsigned long num, char *buffer, int *buf_index,
		int precision, bool uppercase)
{
	int count = 0, num_digits = 0, digit;
	char temp_buffer[16];
	int i = 0;
	unsigned long temp = num;

	do {
		num_digits++;
		temp /= 16;
	} while (temp > 0);

	while (num_digits < precision)
	{
		buffer[(*buf_index)++] = '0';
		count++;
		num_digits++;
	}

	do {
		digit = num % 16;
		if (digit < 10)
			temp_buffer[i++] = digit + '0';
		else
			temp_buffer[i++] = digit - 10 + (uppercase ? 'A' : 'a');
		num /= 16;
	} while (num > 0);

	while (i > 0)
	{
		buffer[(*buf_index)++] = temp_buffer[--i];
		count++;
	}

	return (count);
}
