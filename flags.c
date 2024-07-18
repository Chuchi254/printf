#include "main.h"
#include <string.h>

/**
 * handle_signed_int - handles signed integer with flags
 * @args: list of arguments passed to the _printf function
 * @buffer: buffer to store the output
 * @buf_index: current index in the buffer
 * @plus_flag: boolean indicating if the + flag is specified
 * @space_flag: boolean indicating if the space flag is specified
 *
 * Return: the number of characters printed
 */

int handle_signed_int(va_list args, char *buffer, int *buf_index,
		bool plus_flag, bool space_flag)
{
	int num = va_arg(args, int);
	int count = 0;

	if (num >= 0)
	{
		if (plus_flag)
			buffer[(*buf_index)++] = '+';
		else if (space_flag)
			buffer[(*buf_index)++] = ' ';
		count++;
	}

	count += print_number(num, buffer, buf_index, 0);
	return (count);
}

/**
 * handle_octal_flag - handles octal number with flags
 * @args: list of arguments passed to the _printf function
 * @buffer: buffer to store the output
 * @buf_index: current index in the buffer
 * @hash_flag: boolean indicating if the # flag is specified
 *
 * Return: the number of characters printed
 */

int handle_octal_flag(va_list args, char *buffer, int *buf_index,
		bool hash_flag)
{
	unsigned int num = va_arg(args, unsigned int);
	int count = 0;

	if (hash_flag && num != 0)
	{
		buffer[(*buf_index)++] = '0';
		count++;
	}

	count += handle_octal_direct(num, buffer, buf_index);
	return (count);
}

/**
 * handle_hex_flag - handles hexadecimal number with flags
 * @args: list of arguments passed to the _printf function
 * @buffer: buffer to store the output
 * @buf_index: current index in the buffer
 * @hash_flag: boolean indicating if the # flag is specified
 * @specifier: character indicating the specifier type ('x' or 'X')
 *
 * Return: the number of characters printed
 */

int handle_hex_flag(va_list args, char *buffer, int *buf_index,
		bool hash_flag, char specifier)
{
	unsigned int num = va_arg(args, unsigned int);
	int count = 0;

	if (hash_flag && num != 0)
	{
		buffer[(*buf_index)++] = '0';
		buffer[(*buf_index)++] = (specifier == 'x') ? 'x' : 'X';
		count += 2;
	}

	if (specifier == 'x')
		count += handle_hex_lower_direct(num, buffer, buf_index);
	else
		count += handle_hex_upper_direct(num, buffer, buf_index);

	return (count);
}

/**
 * handle_flags - handles the flag characters +, space, and #
 * @args: list of arguments passed to the _printf function
 * @buffer: buffer to store the output
 * @buf_index: current index in the buffer
 * @flags: string containing the flag characters
 *
 * Return: the number of characters printed
 */

int handle_flags(va_list args, char *buffer, int *buf_index,
		const char *flags)
{
	bool plus_flag = false, space_flag = false, hash_flag = false;
	int count = 0, i;
	char specifier = flags[strlen(flags) - 1];

	for (i = 0; flags[i] != '\0'; i++)
	{
		if (flags[i] == '+')
			plus_flag = true;
		else if (flags[i] == ' ')
			space_flag = true;
		else if (flags[i] == '#')
			hash_flag = true;
	}

	if (specifier == 'd' || specifier == 'i')
		count = handle_signed_int(args, buffer, buf_index, plus_flag, space_flag);
	else if (specifier == '0')
		count = handle_octal_flag(args, buffer, buf_index, hash_flag);
	else if (specifier == 'x' || specifier == 'X')
		count = handle_hex_flag(args, buffer, buf_index, hash_flag, specifier);
	else
		count = dispatch_specifier(args, specifier, buffer, buf_index);

	return (count);
}
