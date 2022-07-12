/* Funciotns to handle other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

/Function to print string in reverse/
int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/Function to print a string in rot 13/
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
