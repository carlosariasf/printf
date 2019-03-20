#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
void copy(char *dest, char *src, int len);
int _strlen(char *);
int null_check(const char *p);
/**
 * _printf - printf function
 *@format: info
 *Return: int
**/
int _printf(const char *format, ...)
{
va_list par;
int i = 0, k = 0, p, len, check;
char text[10240], *c, null[] = "(null)", n = '\0', j = '\n', r = 37;

va_start(par, format);
check = k = null_check(format);
while (check != -1 && format && format[i] != '\0')
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
		else if (format[i] == '\0')
			return (-1);
		else if (format[i] == '%')
		{
			write(1, &r, 1);
			return (1);
		}
		else if (format[i] == 'c')
		{
			p = va_arg(par, int);
			if (p != '\0')
				text[k] = p;
			else if (p == '\0')
			{
				write(1, &n, 1);
				return (1);
			}
			else if (p == '\n')
			{
				write(1, &j, 1);
				return (1);
			}
		}
	}
	else
		text[k] = format[i];
	i++;
	k++;
}
va_end(par);
write(1, text, k);
return (k);
}
/**
 * null_check - check null
 * @p: *char entry
 * Return: -1 if null
**/

int null_check(const char *p)
{
	if (p == NULL)
		return (-1);
return (0);
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
