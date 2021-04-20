#include "../push_swap.h"

void	ft_rra(t_stack **head_stack_a)
{
	t_stack	*tmp;
	t_stack	*new_last;

	write(1, "rra\n", 4);
	if ((*head_stack_a) == NULL || ((*head_stack_a) && !(*head_stack_a)->next))
		return ;
	new_last = (*head_stack_a);
	while (new_last->next->next)
		new_last = new_last->next;
	tmp = new_last->next;
	new_last->next = NULL;
	tmp->next = (*head_stack_a);
	(*head_stack_a) = tmp;
}

void	ft_rrb(t_stack **head_stack_b)
{
	t_stack	*tmp;
	t_stack	*new_last;

	write(1, "rrb\n", 4);
	if ((*head_stack_b) == NULL || ((*head_stack_b) && !(*head_stack_b)->next))
		return ;
	new_last = (*head_stack_b);
	while (new_last->next->next)
		new_last = new_last->next;
	tmp = new_last->next;
	new_last->next = NULL;
	tmp->next = (*head_stack_b);
	(*head_stack_b) = tmp;
}

void	ft_rrr(t_stack **head_stack_a, t_stack **head_stack_b)
{
	write(1, "rrr\n", 4);
	ft_rra(head_stack_a);
	ft_rrb(head_stack_b);
}
