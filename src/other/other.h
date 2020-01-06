#ifndef LEM_IN_V2_OTHER_H
# define LEM_IN_V2_OTHER_H

# include <stdlib.h>
# include <stdint.h>

size_t		ft_strlen(char const *str);

void		exit_error(char *str);

void		ft_memset(void *dest, unsigned char b, size_t size);

char		*ft_strncat(char *str1, const char *str2, size_t n);

int			ft_strcmp(char const *str1, char const *str2);

size_t		ft_atou(char const *str);

char		*ft_strcat(char *str1, const char *str2);

void		int_to_string(char *str, uint32_t nb, uint32_t len);

uint32_t	uintlen(uint32_t nb);

#endif
