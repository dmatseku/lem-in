#include "list_string.h"
#include "unistd.h"
#include "../other/other.h"

void	list_string_print(t_list_string *lst)
{
	while (lst)
	{
		write(1, lst->str, ft_strlen(lst->str));
		write(1, "\n", 1);
		lst = lst->next;
	}
}
