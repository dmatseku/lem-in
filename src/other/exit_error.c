#include <stdlib.h>
#include <unistd.h>
#include "other.h"

void	exit_error(char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	exit(0);
}
