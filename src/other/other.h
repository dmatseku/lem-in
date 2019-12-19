#ifndef LEM_IN_V2_OTHER_H
#define LEM_IN_V2_OTHER_H

#include <stdlib.h>

size_t	ft_strlen(char const * str);

void	exit_error(char *str);

void	ft_memset(void *dest, char b, size_t size);

char	*ft_strncat(char *str1, const char *str2, size_t n);

int		ft_strcmp(char const * str1, char const * str2);

size_t	ft_atou(char const * str);

#endif
