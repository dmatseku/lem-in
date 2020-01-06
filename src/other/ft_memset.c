#include "stdlib.h"

void	ft_memset(void *dest, unsigned char b, size_t size)
{
	unsigned char *c_dest;

	c_dest = (unsigned char*)dest;
	while (size--)
		c_dest[size] = b;
}
