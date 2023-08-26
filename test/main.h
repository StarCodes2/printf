#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

#define BUFFER_SIZE 1024

int _printf(const char *format, ...);
void p_buffer(char *buffer, int *index);
int format_handler(int *index, const char *format, char *buffer, int *b_index,
		va_list list, int flag, int reset);
int b_dformat(va_list list, char *buffer, int *b_index, int flag);
int buffer_int(int num, char *buffer, int *b_index, int flag);
int b_sformat(va_list list, char *buffer, int *b_index, int flag);
int b_cformat(va_list list, char *buffer, int *b_index, int flag);

/**
 * struct non_custom - defines a type for non custom convertion specifiers and
 * their function pointers
 * @conv_s: holds conversion specifier
 * @conv_func: holds the address to the conversion's function
 */

typedef struct non_custom
{
	char conv_s;
	int (*conv_func)(va_list, char *, int *, int);
} non_c;

/**
 * struct non_custom_ch_str - defines a type for char and string conversion
 * specifiers and their functions
 * @conv_s: holds conversion specifiers
 * @conv_func: holds the address to the conversion function
 */

typedef struct non_custom_ch_str
{
	char conv_s;
	int (*conv_func)(va_list, char *, int *, int);
} ch_str;

#endif
