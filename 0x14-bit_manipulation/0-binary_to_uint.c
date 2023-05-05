#include "main.h"

/**
 * binary_to_uint - converts a binary number to unsigned int
 *
 * @b: string containing the binary number
 *
 * Return: the converted number
*/

unsigned int binary_to_uint(const char *b)
{
	int i;
	unsigned int set_val = 0;

	if (!b)
		return (0);

	for (i = 0; b[i]; i++)
	{
		if (b[i] < '0' || b[i] > '1')
			return (0);
		set_val  = 2 * set_val + (b[i] - '0');
	}

	return (set_val);
}
