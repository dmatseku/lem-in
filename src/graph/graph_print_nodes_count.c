#include <unistd.h>
#include <stdint.h>
#include "../other/other.h"
#include "../manage_flags/manage_flags.h"

void		graph_print_nodes_count(uint32_t nodes_count)
{
	char		*output;
	uint32_t	len;
	uint32_t	nb_len;

	if (!flags[ROOMS])
		return;
	nb_len = uintlen(nodes_count);
	len = 17 + nb_len + 1;
	if (!(output = (char*)malloc(sizeof(char) * len)))
		exit_error("Malloc error");
	ft_memset(output, 0, len);
	ft_strcat(output, "Number of rooms: ");
	int_to_string(output + 17, nodes_count, nb_len);
	write(1, "\n", 1);
	write(1, output, len - 1);
	write(1, "\n", 1);
	free(output);

}
