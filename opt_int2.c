#include <stdlib.h>
#include <stdarg.h>
#include "holberton.h"
/**
 *op_int - prints int numbers
 *
 *@k: number to print
 *
 *Return: the number of bytes
 */
char *op_int(va_list k)
{
	int a = 0, b, c = 0, d = 0, e = 1, f = 0, m = 0, n = 0, l = 0;
	char *x;

	a = va_arg(k, int);
	f = a;
	if (a == -2147483648)
		a = a + 1;
	if (a < 0)
	{	l = 1;
		a = a * -1;
	}
	d = a;
	for (b = 0; a != 0; b++)
	{	a = a / 10;
		if (c == 1)
			e = e * 10;
		c = 1;
	}
	c = b;
	x = malloc(b + l + 1);
	if (x == NULL)
	{	free(x);
		return (NULL);
	}
	if (l == 1)
		x[0] = '-';
	for (; b > 0; b--, l++)
	{	m = d / e;
		n = m % 10;
		e = e / 10;
		if (m < 10)
		{	x[l] = m + '0';
		}
		else
		{	x[l] = n + '0';
			if (f == -2147483648 && e == 0)
				x[l] = '8';
		}
	}
	if (f == 0)
		x[0] = '0';
	return (x);
}
