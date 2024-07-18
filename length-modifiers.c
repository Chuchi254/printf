#include "main.h"

/**
 * handle_length_modifiers - handles the length modifiers l and h
 * @args: list of arguments passed to the _printf function
 * @length: string containing the length modifier (either 'l' or 'h')
 * @buffer: buffer to store the output
 * @buf_index: current index in the buffer
 * @width: space to be left
 *
 * Return: the number of characters printed
 */

int handle_length_modifiers(
		va_list args, char length, char *buffer, int *buf_index, int width)
{
	if (length == 'l')
		return (
				handle_length_l(args, length, buffer, buf_index, width, 0, false, false));
	else if (length == 'h')
		return (
				handle_length_h(args, length, buffer, buf_index, width, 0, false, false));
	else
		return (dispatch_specifier(args, length, buffer, buf_index));
}
