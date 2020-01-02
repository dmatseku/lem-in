#include "manage_flags.h"
#include <stdlib.h>

void flags_delete(void)
{
	free(flags);
}
