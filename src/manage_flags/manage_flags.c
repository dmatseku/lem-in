#include "manage_flags.h"
#include "../other/other.h"
#include <stdint.h>

bool	*g_flags;

void	manage_flags(int ac, char **av)
{
	char const *const restrict	arr[] = {"-help", "-color", "-last",
										"-paths", "-rooms", "-steps"};
	int32_t						i;

	if (!(g_flags = (bool*)malloc(sizeof(bool) * FLAGS_COUNT)))
		exit_error("Malloc error");
	ft_memset(g_flags, 0, sizeof(bool) * FLAGS_COUNT);
	i = 1;
	while (i < ac)
	{
		if (!ft_strcmp(av[i], arr[HELP]))
			g_flags[HELP] = true;
		else if (!ft_strcmp(av[i], arr[COLOR]))
			g_flags[COLOR] = true;
		else if (!ft_strcmp(av[i], arr[LAST]))
			g_flags[LAST] = true;
		else if (!ft_strcmp(av[i], arr[PATHS]))
			g_flags[PATHS] = true;
		else if (!ft_strcmp(av[i], arr[ROOMS]))
			g_flags[ROOMS] = true;
		else if (!ft_strcmp(av[i], arr[STEPS]))
			g_flags[STEPS] = true;
		i++;
	}
}
