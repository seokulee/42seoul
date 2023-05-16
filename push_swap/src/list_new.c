#include "push_swap.h"

t_list	*list_new(void)
{
	t_list	*new_list;

	new_list = (t_list *)malloc(sizeof(t_list));
	if (new_list == NULL)
		return (NULL);
	new_list->head = NULL;
	new_list->tail = NULL;
	new_list->count = 0;
	return (new_list);
}
