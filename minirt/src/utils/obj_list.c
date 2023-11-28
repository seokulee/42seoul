/* 이거 들어가있는 헤더 수정 필요 */
#include "math_vec.h"

void		obj_add(t_object **list, t_object *new)
{
	t_object	*cur;

	if (*list == NULL)
	{
		*list = new;
		return ;
	}
	else
	{
		cur = *list;
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = new;
	}
}

t_object	*obj_last(t_object **list)
{
	t_object	*cur;

	if (*list == NULL)
		return (NULL);
	cur = *list;
	while (cur->next)
		cur = cur->next;
	return (cur);
}
