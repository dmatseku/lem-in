#include <limits.h>
#include <stdlib.h>

size_t	ft_atou(char const *str)
{
	size_t		res;

	res = 0;
	while (*str && ((*str >= 9 && *str <= 13) || *str == ' '))
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		if (ULONG_MAX - res < (size_t)(*str - 48))
			return (0);
		res = res * 10 + *str - 48;
		str++;
	}
	return (res);
}
