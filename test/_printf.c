#include "main.h"

/**
 * _printf - prints formatted string to standard output
 * @format: points to the string passed as the first argument
 *
 * Return: returns the number of printed characters
 */

int _printf(const char *format, ...)
{
	va_list list;
	int i, reset, flag, b_index = 0, char_printed = 0;
	char buffer[BUFFER_SIZE];

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(list, format);
	for (i = 0; format[i]; i++)
	{
		if (b_index == BUFFER_SIZE)
			p_buffer(buffer, &b_index);

		if (format[i] != '%')
		{
			buffer[b_index++] = format[i];
			char_printed++;
		}
		else
		{
			if (format[i + 1] == '%')
			{
				buffer[b_index++] = format[i++];
				char_printed++;
				continue;
			}
			reset = i++;

			if (format[i] == ' ' || format[i] == '\0')
				return (-1);
			flag = -1; /* get_flag(&i, format); */
			char_printed += format_handler(&i, format, buffer,
					&b_index, list, flag, reset);
		}
	}
	p_buffer(buffer, &b_index);
	va_end(list);
	return (char_printed);
}

/**
 * format_handler - selects the right function to handle the format of a
 * specific conversion specifier
 * @index: points to format string index
 * @format: points to the format string
 * @buffer: points to the buffer
 * @b_index: points to the buffer's index
 * @list: contains the variadic argument list
 * @flag: contains the flag identifier digit
 * @reset: contains the index of the last % character
 *
 * Return: returns the number of characters buffered
 */

int format_handler(int *index, const char *format, char *buffer, int *b_index,
		va_list list, int flag, int reset)
{
	int i, count = 0, found = 0;
	non_c nc_func[] = {
		{'d', b_dformat},
		{'i', b_dformat}
	};

	ch_str cs_func[] = {
		{'c', b_cformat},
		{'s', b_sformat}
	};

	for (i = 0; i < 2; i++)
	{
		if (nc_func[i].conv_s == format[*index])
		{
			count += nc_func[i].conv_func(list, buffer, b_index, flag);
			found = 1;
		}
	}

	for (i = 0; i < 2; i++)
	{
		if (cs_func[i].conv_s == format[*index])
		{
			count += cs_func[i].conv_func(list, buffer, b_index, flag);
			found = 1;
		}
	}

	if (found == 0)
	{
		for (i = reset; i <= *index; i++)
		{
			buffer[*b_index] = format[i];
			*b_index += 1;
			count++;
		}
	}

	return (count);
}

/**
 * p_buffer - prints the content of the buffer
 * @buffer: points to the buffer
 * @index: points to the buffer index, used to represent the number of
 * characters to be printed
 */

void p_buffer(char *buffer, int *index)
{
	if (*index > 0)
		write(1, buffer, *index);

	*index = 0;
}
