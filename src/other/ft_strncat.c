#include <stdlib.h>

char	*ft_strncat(char *str1, const char *str2, size_t n)
{
	char *const res = str1;

	while (*str1 != '\0')
		str1++;
	while (n-- > 0 && *str2 != '\0')
	{
		*str1 = *str2;
		str1++;
		str2++;
	}
	*str1 = '\0';
	return (res);
}
