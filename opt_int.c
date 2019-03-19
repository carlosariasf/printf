#include <stdarg.h>
#include "holberton.h"
/**
 *op_int - prints int numbers
 *
 *@l: number to print
 *
 *Return: the number of bytes
 */
int op_int(va_list l)
{
	int a = 0, b = 0, c = 0, d = 0, e = 1, f = 0, m = 0, n = 0;
	char x;

	a = va_arg(l, int);
	f = a;
	if (a == -2147483648)
		a = a + 1;
	if (a < 0)
	{
		_putchar('-');
		a = a * -1;
	}
	d = a;
	for (b = 0; a != 0; b++)
	{
		a = a / 10;
		if (c == 1)
			e = e * 10;
		c = 1;
	}
	c = b;
	for (; b > 0; b--)
	{
		m = d / e;
		n = m % 10;
		e = e / 10;
		if (m < 10)
		{
			x = m + '0';
			_putchar(x);
		}
		else
		{
			x = n + '0';
			if (f == -2147483648 && e == 0)
				x = '8';
			_putchar(x);
		}
	}
	return (c);
}
