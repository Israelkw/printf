#include <stdarg.h>
#include <unistd.h>
#include "main.h"
#include <stdio.h>
/**
 * print_string - prints a string
 * @s: the string to print
 *
 * Return: the number of characters printed
 */
int print_string(char *s)
{
	int i = 0;

	if (s == NULL)
		s = "(null)";
	while (s[i])
	{
		_putchar(s[i]);
		i++;
	}
	return (i);
}

/**
 * _printf - prints output according to a format.
 * @format: character string.
 *Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0;
	int count = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					count += _putchar(va_arg(args, int));
					break;
				case 's':
					count += print_string(va_arg(args, char *));
					break;
				case '%':
					count += _putchar('%');
					break;
				default:
					count += _putchar('%');
					count += _putchar(format[i]);
					break;
			}
		}
		else
		{
			count += _putchar(format[i]);
		}
		i++;
	}
	va_end(args);
	return (count);
}
