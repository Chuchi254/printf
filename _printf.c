#include "main.h"

/**
 * handle_format_specifier - handles format specifiers in the format string
 * @p: pointer to the current position in the format string
 * @args: list of arguments passed to the _printf function
 * @buffer: buffer to store the output
 * @buf_index: current index in the buffer
 *
 * Return: the number of character printed
 */

int handle_format_specifier(const char **p, va_list args, char *buffer,
		int *buf_index)
{
	int count = 0, width = 0, precision = -1;

	while (**p >= '0' && **p <= '9')
	{
		width = width * 10 + (**p - '0');
		(*p)++;
	}

	if (**p == '.')
	{
		(*p)++;
		precision = 0;
		while (**p >= '0' && **p <= '9')
		{
			precision = precision * 10 + (**p - '0');
			(*p)++;
		}
	}

	count += handle_specifier(args, **p, buffer, buf_index, width, precision);
	return (count);
}

/**
 * _printf - produces output according to a format
 * @format: format string containing the characters and the specifiers
 *
 * Return: the number of chracters pritned (excluding the null byte)
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0, buf_index = 0;
	const char *p;
	char buffer[1024];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (p = format; *p != '\0'; p++)
	{
		if (*p == '%')
		{
			p++;
			count += handle_format_specifier(&p, args, buffer, &buf_index);
		}
		else
		{
			buffer[buf_index++] = *p;
			count++;
		}
		if (buf_index >= 1024)
			flush_buffer(buffer, &buf_index);
	}

	flush_buffer(buffer, &buf_index);
	va_end(args);
	return (count);
}
