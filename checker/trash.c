#include "checker.h"

void	ft_free_stack(t_stack *head)
{
	t_stack	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

void    ft_print(t_stack *head)
{
	while (head)
	{
		printf("%d ", head->value);
		head = head->next;
	}
}