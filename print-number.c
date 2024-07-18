#include "main.h"

/**
 * print_number - prints a long integer number
 * @num: the integer to print
 * @buffer: buffer to store the output
 * @buf_index: current index in the buffer
 * @precision: precision for the conversion specifier
 *
 * Return: the number of characters printed
 */

int print_number(long num, char *buffer, int *buf_index, int precision)
{
	int count = 0, num_digits = 0, i = 0;
	unsigned long abs_num = num, temp;
	char temp_buffer[20];

	if (num < 0)
	{
		buffer[(*buf_index)++] = '-';
		count++;
		abs_num = -num;
	}
	else
		abs_num = num;
	temp = abs_num;
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
		temp_buffer[i++] = (abs_num % 10) + '0';
		abs_num /= 10;
	} while (abs_num > 0);

	while (i > 0)
	{
		buffer[(*buf_index)++] = temp_buffer[--i];
		count++;
	}

	return (count);
}
