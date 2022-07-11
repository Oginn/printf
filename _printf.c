#include "main.h"

/**
 **get_print - selects the right printing function
 * depending on the conversion specifier passed to _printf
 * @s: character that holds the conversion specifier
 * Return: the resulting null byte
 */
int (*get_print(char s))(va_list, flags_t *)
{
	pt functs[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'d', print_int},
		{'i', print_int}
		};
	int flags = 5;

	register int a;

	for (a = 0; a < flags; a++)
	if (functs[a].fs == s)
	return (functs[a].printer);
	return (NULL);
}
/**
 * get_flag - turns on flags if _printf finds
 * a flag modifier in the format string
 * @s: character that holds the flag specifier
 * @printer: pointer to the struct flags in which we turn the flags on
 *
 * Return: 1 if a flag has been turned on, 0 otherwise
 */
int get_flag(char s, flags_t *printer)
{
	int i = 0;

	switch (s)
	{
		case '+':
			printer->plus = 1;
			i = 1;
			break;
		case ' ':
			printer->space = 1;
			i = 1;
			break;
		case '#':
			printer->hash = 1;
			i = 1;
			break;
	}

	return (i);
}

/**
 * _printf - mimic printf from stdio
 * Description: produces output according to a format
 * write output to stdout, the standard output stream
 * @format: character string composed of zero or more directives
 *
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
 * return -1 for incomplete identifier error
 */

int _printf(const char *format, ...)
{
	int (*pfunc)(va_list, flags_t *);
	const char *p;
	va_list arg;
	flags_t flags = {0, 0, 0};

	register int count = 0;

	va_start(arg, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = format; *p; p++)
	{
		if (*p == '%')
		{
			p++;
			if (*p == '%')
			{
				count += _putchar('%');
				continue;
			}
			while (get_flag(*p, &flags))
				p++;
			pfunc = get_print(*p);
			count += (pfunc)
				? pfunc(arg, &flags)
				: _printf("%%%c", *p);
		} else
			count += _putchar(*p);
	}
	_putchar(-1);
	va_end(arg);
	return (count);
}
