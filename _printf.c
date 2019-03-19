#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
void copy(char *dest, char *src, int len);
int _strlen(char *);
/**
 * _printf - printf function
 *@format: info
 *Return: int
**/
int _printf(const char *format, ...)
{
va_list par;
int i = 0, k = 0, p, len;
char text[1024], *c, null[] = "(null)";
;

va_start(par, format);
while (format && format[i] != '\0')
{
	if (format[i - 1] != '\\' && format[i] == '%')
	{
		i++;
		if (format[i] == 's')
		{
			c = va_arg(par, char *);
			len = _strlen(c);
			if (!c)
			{
				copy((text + k), null, 6);
				k += 6;
			}
			else
			{
				copy((text + k), c, len);
				k += len;
			}
			i++;
			continue;
		}
		else if (format[i] == '%')
			text[k] = format[i];
		else if (format[i] == 'c')
		{
			p = va_arg(par, int);
			(p) ? text[k] = p : k--;
		}
	}
	else
		text[k] = format[i];
	i++;
	k++;
}
va_end(par);
return (write(1, text, k));
}
/**
 * copy - copy
 * @dest: dest
 * @src: src
 * @n: n
 * Return: None
 */
void copy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];
}
/**
 * _strlen - length
 * @s: char *
 * Return: Length
 */
int _strlen(char *s)
{
	int i;

	if (s == NULL)
		return (0);
	for (i = 0; s[i] != '\0'; i++)
		;
	return (i);
}
