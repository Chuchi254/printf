#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>

/* Prototytpes */
int print_char(char c, char *buffer, int *buf_index);
int print_string(char *s, char *buffer, int *buf_index);
int handle_characters(va_list args, char specifier, char *buffer,
		int *buf_index);
int handle_precision(va_list args, char specifier, char *buffer,
		int *buf_index, int precision);
int handle_specifier(va_list args, char specifier, char *buffer,
		int *buf_index, int width, int precision);
int handle_integers(va_list args, char *buffer, int *buf_index);
int handle_binary(va_list args, char *buffer, int *buf_index);
int handle_unsigned_int(va_list args, char *buffer, int *buf_index);
int handle_octal(va_list args, char *buffer, int *buf_index);
int handle_hex_lower(va_list args, char *buffer, int *buf_index);
int handle_hex_upper(va_list args, char *buffer, int *buffer_index);
int handle_custom_string(va_list args, char *buffer, int *buf_index);
int handle_pointer(va_list args, char *buffer, int *buf_index);
void flush_buffer(char *buffer, int *buf_index);
int handle_flags(va_list args, char *buffer, int *buf_index,
		const char *flags);
int print_number(long num, char *buffer, int *buf_index, int precision);
int print_unsigned_number(unsigned long num, char *buffer,
		int *buf_index, int precision);
int print_octal(unsigned long num, char *buffer, int *buf_index,
		int precision);
int print_hex(unsigned long num, char *buffer, int *buf_index,
		int precision, bool uppercase);
int handle_length_modifiers(va_list args, char length, char *buffer,
		int *buf_index, int width);
int handle_length_l(va_list args, char specifier, char *buffer,
		int *buf_index, int width, int precision, bool zero_flag, bool left_align);
int handle_length_h(va_list args, char specifier, char *buffer,
		int *buf_index, int width, int precision, bool zero_flag, bool left_align);
int handle_field_width(va_list args, char specifier, char *buffer,
		int *buf_index, int width);
int handle_reversed(va_list args, char *buffer, int *buf_index);
int handle_rot13(va_list args, char *buffer, int *buf_index);
int dispatch_specifier(va_list args, char specifier, char *buffer,
		int *buf_index);
int _printf(const char *format, ...);
int handle_octal_direct(unsigned int num, char *bufffer, int *buf_index);
int handle_hex_lower_direct(
		unsigned int num, char *buffer, int *buf_index);
int handle_hex_upper_direct(
		unsigned int num, char *buffer, int *buf_index);

#endif /* MAIN_H */
