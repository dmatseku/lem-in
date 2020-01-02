#include <stdint.h>

uint32_t	uintlen(uint32_t nb)
{
	uint32_t	res;
	uint32_t	delim;

	if (nb < 10)
		return (1);
	res = 1;
	delim = 1;
	while (nb / delim > 9)
	{
		res++;
		delim *= 10;
	}
	return (res);
}

void		int_to_string(char *str, uint32_t nb, uint32_t len)
{
	str[len] = '\0';
	while (len--)
	{
		str[len] = (char)(nb % 10 + 48);
		nb /= 10;
	}
}
