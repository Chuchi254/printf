#include "main.h"

/**
 * handle_octal_direct - handles the conversion specifier o for octal
 * @num: unsigned integer to convert
 * @buffer: buffer to store the output
 * @buf_index: current index in the buffer
 *
 * Return: the number of characters printed
 */

int handle_octal_direct(unsigned int num, char *buffer, int *buf_index)
{
	int count = 0, i = 0;
	char temp_buffer[12];

	if (num == 0)
	{
		buffer[(*buf_index)++] = '0';
		return (1);
	}

	while (num > 0)
	{
		temp_buffer[i++] = (num % 8) + '0';
		num /= 8;
	}

	while (i > 0)
	{
		buffer[(*buf_index)++] = temp_buffer[--i];
		count++;
	}

	return (count);
}

/**
 * handle_hex_lower_direct - handles the conversion specifier x for
 * hexadecimal (lowercase)
 * @num: unsigned integer to convert
 * @buffer: buffer to store the output
 * @buf_index: current index in the buffer
 *
 * Return: the number of characters printed
 */

int handle_hex_lower_direct(unsigned int num, char *buffer, int *buf_index)
{
	int count = 0, digit, i = 0;
	char temp_buffer[16];

	if (num == 0)
	{
		buffer[(*buf_index)++] = '0';
		return (1);
	}

	while (num > 0)
	{
		digit = num % 16;
		if (digit < 10)
			temp_buffer[i++] = digit = '0';
		else
			temp_buffer[i++] = digit - 10 + 'a';
		num /= 16;
	}

	while (i > 0)
	{
		buffer[(*buf_index)++] = temp_buffer[--i];
		count++;
	}

	return (count);
}

/**
 * handle_hex_upper_direct - handles the conversion specifier
 * @num: unsigned integer to convert
 * @buffer: buffer to store the output
 * @buf_index: current index in the buffer
 *
 * Return: the number of characters printed
 */

int handle_hex_upper_direct(unsigned int num, char *buffer, int *buf_index)
{
	int count = 0, i = 0, digit;
	char temp_buffer[16];

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
