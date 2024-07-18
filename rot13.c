#include "main.h"

/**
 * handle_rot13 - handles the custom conversion specifier R
 * @args: list of arguments passed to the _printf function
 * @buffer: buffer to store the output
 * @buf_index: current index in the buffer
 *
 * Return: the number of characters printed
 */

int handle_rot13(va_list args, char *buffer, int *buf_index)
{
	char *str = va_arg(args, char *);
	char *alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *rot13 = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	int i, j;

	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; alpha[j] != '\0'; j++)
		{
			if (str[i] == alpha[j])
			{
				buffer[(*buf_index)++] = rot13[j];
				break;
			}
		}
		if (alpha[j] == '\0')
			buffer[(*buf_index)++] = str[i];
	}

	return (i);
}
