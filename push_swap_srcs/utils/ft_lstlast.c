#include "../push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*go;

	go = lst;
	if (lst)
	{
		while (go->next != NULL)
			go = go->next;
	}
	return (go);
}
