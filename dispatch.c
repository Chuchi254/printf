#include "main.h"

/**
 * handle_numeric_specifiers - handles numeric specifiers
 * @args: list of arguments passed to the _printf function
 * @specifier: character indicating the specifier type
 * @buffer: buffer to store the output
 * @buf_index: current index in the buffer
 *
 * Return: the numbre of characters printed
 */

int handle_numeric_specifiers(va_list args, char specifier,
		char *buffer, int *buf_index)
{
	switch (specifier)
	{
		case 'd':
		case 'i':
			return (handle_integers(args, buffer, buf_index));
		case 'u':
			return (handle_unsigned_int(args, buffer, buf_index));
		case 'o':
			return (handle_octal(args, buffer, buf_index));
		case 'x':
			return (handle_hex_lower(args, buffer, buf_index));
		case 'X':
			return (handle_hex_upper(args, buffer, buf_index));
		default:
			return (0);
	}
}

/**
 * handle_misc_specifiers - handles miscellaneous specifiers
 * @args: list of arguments passed to the _printf function
 * @specifier: character indicating the specifier type
 * @buffer: buffer to store the output
 * @buf_index: current index in the buffer
 *
 * Return: the number of characters printed
 */

int handle_misc_specifiers(va_list args, char specifier, char *buffer,
		int *buf_index)
{
	switch (specifier)
	{
		case 'S':
			return (handle_custom_string(args, buffer, buf_index));
		case 'p':
			return (handle_pointer(args, buffer, buf_index));
		case 'r':
			return (handle_reversed(args, buffer, buf_index));
		case 'R':
			return (handle_rot13(args, buffer, buf_index));
		default:
			return (0);
	}
}

/**
 * dispatch_specifier - dispatches the specifier to the correct
 * handler function
 * @args: list of arguments passed to the _printf function
 * @specifier: character indicating the specifier type
 * @buffer: buffer to store the output
 * @buf_index: current index in the buffer
 *
 * Return: the number of characters printed
 */

int dispatch_specifier(va_list args, char specifier, char *buffer,
		int *buf_index)
{
	int count = 0;

	switch (specifier)
	{
		case 'c':
		case 's':
		case '%':
			count = handle_characters(args, specifier, buffer, buf_index);
			break;
		case 'd':
		case 'i':
		case 'u':
		case 'o':
		case 'x':
		case 'X':
			count = handle_numeric_specifiers(args, specifier, buffer, buf_index);
			break;
		case 'S':
		case 'p':
		case 'r':
		case 'R':
			count = handle_misc_specifiers(args, specifier, buffer, buf_index);
			break;
		case 'b':
			count = handle_binary(args, buffer, buf_index);
			break;
		default:
			buffer[(*buf_index)++] = '%';
			buffer[(*buf_index)++] = specifier;
			count = 2;
			break;
	}

	return (count);
}
