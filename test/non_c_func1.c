#include "main.h"

/**
 * b_dformat - saves a formatted digit to buffer as string
 * @list: contains a list of variadic arguments
 * @buffer: points to the buffer
 * @b_index: points to the buffer index
 * @flag: contains a flag identifier digit
 *
 * Return: the number of characters buffered
 */

int b_dformat(va_list list, char *buffer, int *b_index, int flag)
{
	int num = va_arg(list, int);

	return (buffer_int(num, buffer, b_index, flag));
}

/**
 *  * buffer_int - saves a formatted digit to buffer as string
 * @num: contains the number to be buffered
 * @buffer: points to the buffer
 * @b_index: points to the buffer index
 * @flag: contains a flag identifier digit
 *
 * Return: the number of characters buffered
 */

int buffer_int(int num, char *buffer, int *b_index, int flag)
{
	int count = 0;

	if (flag > 0)
		flag = -1;

	if (num < 0)
	{
		buffer[*b_index] = '-';
		*b_index += 1;
		count++;
		num = -num;
	}

	if (num > 9)
		count += buffer_int(num / 10, buffer, b_index, flag);

	buffer[*b_index] = (num % 10) + '0';
	*b_index += 1;

	return (++count);
}
/**
 * b_sformat - saves a formatted string to buffer
 * @list: contains a list of variadic arguments
 * @buffer: points to the buffer
 * @b_index: points to the buffer index
 * @flag: contains a flag identifier digit
 *
 * Return: the number of characters buffered
 */

int b_sformat(va_list list, char *buffer, int *b_index, int flag)
{
	int count = 0;
	char *s = va_arg(list, char *);

	if (flag > 0)
		flag = -1;

	if (s == NULL)
		s = "(null)";

	while (s[count])
	{
		buffer[*b_index] = s[count];
		*b_index += 1;
		count++;
	}

	return (count);
}

/**
 * b_cformat - saves a formatted character to buffer
 * @list: contains a list of variadic arguments
 * @buffer: points to the buffer
 * @b_index: points to the buffer index
 * @flag: contains a flag identifier digit
 *
 * Return: the number of characters buffered
 */

int b_cformat(va_list list, char *buffer, int *b_index, int flag)
{
	unsigned char c = va_arg(list, int);

	if (flag > 0)
		flag = -1;

	buffer[*b_index] = c;
	*b_index += 1;

	return (1);
}
