#include <unistd.h>
#include <stdarg.h>
/**
 * _printf - printf function
 *@format: info
 *
 *Return: int
 *
**/
int _printf(const char *format, ...)
{
va_list par;
int i = 0, j = 0, k = 0, p;
char text[1024], *c;

va_start(par, format);
while (format && format[i] != '\0')
{
	if (format[i - 1] != '\\' && format[i] == '%')
	{
		if (format[i + 1] == 'c')
		{
			p = va_arg(par, int);
			text[k] = p;
			k++;
		}
		else if (format[i + 1] == 's')
		{
			c = va_arg(par, char *);
			while (c[j] != '\0')
			{
				text[k] = c[j];
				k++, j++;
			}
		j = 0;
		}
	i++;
	}
	else
	{
		text[k] = format[i];
		k++;
	}
i++;
}
va_end(par);
return (write(1, text, k));
}
