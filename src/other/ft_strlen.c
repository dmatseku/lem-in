#include <stdlib.h>

size_t	ft_strlen(char const *const restrict str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}
