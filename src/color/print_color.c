#include <unistd.h>
#include "color.h"
#include "../manage_flags/manage_flags.h"

void	print_color(t_colors color)
{
	static char* colors[] = {"[31m", "[32m", "[33m", "[34m", "[35m", "[36m"};

	if (!flags[COLOR])
		return ;
	write(1, "\033", 1);
	if (color == CLEAR)
		write(1, "[0m", 3);
	else
		write(1, colors[color], 4);
}
