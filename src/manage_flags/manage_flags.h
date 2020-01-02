#ifndef LEM_IN_V2_MANAGE_FLAGS_H
#define LEM_IN_V2_MANAGE_FLAGS_H
#define FLAGS_COUNT 6

#include <stdint.h>
#include <stdbool.h>

extern bool		*flags;

typedef enum	e_flags
{
				HELP = 0,
				COLOR,
				LAST,
				PATHS,
				ROOMS,
				STEPS
}				t_flags;

void			manage_flags(int ac, char **av);

void			flags_delete(void);

#endif
