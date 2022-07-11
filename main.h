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
int print_char(va_list l, flags_t *printer);
int print_string(va_list l, flags_t *printer);
int print_percent(va_list l, flags_t *printer);
char *convert(unsigned long int num, int base, int lowercase);
/* _printf */
int _printf(const char *format, ...);
int get_flag(char s, flags_t *printer);
int (*get_print(char s))(va_list, flags_t *);
/* print_nums */
int print_int(va_list l, flags_t *printer);
void print_number(int n);
int count_digit(int i);


#endif // MAIN_H
