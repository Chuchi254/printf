#include <unistd.h>

/**
 * flush_buffer - writes the buffer to stdout and resets the buffer index
 * @buffer: the buffer to flush
 * @buf_index: the current index in the buffer
 */

void flush_buffer(char *buffer, int *buf_index)
{
	if (*buf_index > 0)
	{
		write(1, buffer, *buf_index);
		*buf_index = 0;
	}
}
