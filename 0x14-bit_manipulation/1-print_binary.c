#include "main.h"

/**
 * print_binary - prints the binary equivalent of a decimal number
 *
 * @n: number to print in binary
*/

void print_binary(unsigned long int n)
{
	int i, con  = 0;
	unsigned long int cur;

	for (i = 63; i >= 0; i--)
	{
		cur = n >> i;

		if (cur & 1)
		{
			_putchar('1');
			con++;
		}
		else if (con)
			_putchar('0');
	}
	if (!con)
		_putchar('0');
}
