#include "manage_flags.h"
#include "../other/other.h"
#include <stdint.h>

bool	*flags;

void	manage_flags(int ac, char **av)
{
	char const * const restrict arr[] = {"-help", "-color", "-last",
				  						"-paths", "-rooms", "-steps"};
	int32_t						i;

	if (!(flags = (bool*)malloc(sizeof(bool) * FLAGS_COUNT)))
		exit_error("Malloc error");
	ft_memset(flags, 0, sizeof(bool) * FLAGS_COUNT);
	i = 1;
	while (i < ac)
	{
		if (!ft_strcmp(av[i], arr[HELP]))
			flags[HELP] = true;
		else if (!ft_strcmp(av[i], arr[COLOR]))
			flags[COLOR] = true;
		else if (!ft_strcmp(av[i], arr[LAST]))
			flags[LAST] = true;
		else if (!ft_strcmp(av[i], arr[PATHS]))
			flags[PATHS] = true;
		else if (!ft_strcmp(av[i], arr[ROOMS]))
			flags[ROOMS] = true;
		else if (!ft_strcmp(av[i], arr[STEPS]))
			flags[STEPS] = true;
		i++;
	}
}
