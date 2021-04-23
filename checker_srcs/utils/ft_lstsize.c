#include "../checker.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*go;
	int		c;

	go = lst;
	c = 0;
	while (go)
	{
		c++;
		go = go->next;
	}
	return (c);
}
