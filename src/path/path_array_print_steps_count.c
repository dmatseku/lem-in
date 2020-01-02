#include <unistd.h>
#include <stdint.h>
#include "../other/other.h"
#include "../manage_flags/manage_flags.h"

void		path_array_print_steps_count(uint32_t steps)
{
	char		*output;
	uint32_t	len;
	uint32_t	nb_len;

	if (!flags[STEPS])
		return;
	nb_len = uintlen(steps);
	len = 32 + nb_len + 1;
	if (!(output = (char*)malloc(sizeof(char) * len)))
		exit_error("Malloc error");
	ft_memset(output, 0, len);
	ft_strcat(output, "Here is the number of my lines: ");
	int_to_string(output + 32, steps, nb_len);
	write(1, "\n", 1);
	write(1, output, len - 1);
	write(1, "\n", 1);
	free(output);
}
