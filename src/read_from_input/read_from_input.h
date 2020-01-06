#ifndef LEM_IN_V2_READ_FROM_INPUT_H
# define LEM_IN_V2_READ_FROM_INPUT_H

# include "../list_string/list_string.h"

int				read_line(char **str, int fd);

t_list_string	*read_from_input(int fd);

#endif
