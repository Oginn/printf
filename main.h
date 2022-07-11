#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>

/**
 * struct flags - struct containing flags to "turn on"
 * when a flag specifier is passed to _printf()
 * @plus: flag for the '+' character
 * @space: flag for the ' ' character
 * @hash: flag for the '#' character
 */
typedef struct flags
{
	int plus;
	int space;
	int hash;
} flags_t;

/**
 * struct printType - struct to choose the right function depending
 * on the format specifier passed to _printf()
 * @fs: format specifier
 * @printer: pointer to the correct printing function
 */
typedef struct printType
{
	char fs;
	int (*printer)(va_list ap, flags_t *printer);
} pt;

int _putchar(char c);
int _puts(char *str);
int _printf(const char *format, ...);
int print_char(va_list l, flags_t *printer);
int print_string(va_list l, flags_t *printer);
int print_percent(va_list l, flags_t *printer);

#endif // MAIN_H

