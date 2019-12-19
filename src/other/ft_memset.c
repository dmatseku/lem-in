#include "stdlib.h"

void ft_memset(void *dest, char b, size_t size)
{
	char *c_dest;

	c_dest = (char*)dest;
	while (size--)
		c_dest[size] = b;
}
