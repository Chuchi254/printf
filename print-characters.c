#include "main.h"

/**
 * print_char - prints a single character to the buffer
 * @c: the character to pritn
 * @buffer: buffer to store the output
 * @buf_index: current index in the buffer
 *
 * Return: the number of characters printed
 */

int print_char(char c, char *buffer, int *buf_index)
{
	buffer[(*buf_index)++] = c;
	return (1);
}

/**
 * print_string - prints a sring to the buffer
 * @s: the string to print
 * @buffer: buffer to store the output
 * @buf_index: current index in the buffer
 *
 * Return: the number of characters printed
 */

int print_string(char *s, char *buffer, int *buf_index)
{
	int count = 0;

	if (s == NULL)
		s = "(null)";
	while (*s)
	{
		buffer[(*buf_index)++] = *s++;
		count++;
	}

	return (count);
}
