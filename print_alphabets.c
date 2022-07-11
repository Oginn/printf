#include "main.h"


/**
 * print_char - prints a character
 * @l: va_list arguments from _printf
 * @printer: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: number of char printed
 */
int print_char(va_list l, flags_t *printer)
{
	(void)printer;
	_putchar(va_arg(l, int));
	return (1);
}
/**
 * print_string - loops through a string and prints
 * every character
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: number of char printed
 */
int print_string(va_list l, flags_t *printer)
{
	char *s = va_arg(l, char *);

	(void)printer;

	if (!s)
		s = "(null)";
	return (_puts(s));
}

