#include "../push_swap.h"

void	ft_rra(t_stack **head_stack_a, t_stack **head_stack_b, int debug_flag)
{
	t_stack	*tmp;
	t_stack	*new_last;

	write(1, "rra\n", 4);
	if ((*head_stack_a) == NULL || ((*head_stack_a) && !(*head_stack_a)->next))
	{
		if (debug_flag)
			ft_print_stacks(*head_stack_a, *head_stack_b, "rra\n");
		return ;
	}
	new_last = (*head_stack_a);
	while (new_last->next->next)
		new_last = new_last->next;
	tmp = new_last->next;
	new_last->next = NULL;
	tmp->next = (*head_stack_a);
	(*head_stack_a) = tmp;
	if (debug_flag)
		ft_print_stacks(*head_stack_a, *head_stack_b, "rra\n");
}

void	ft_rrb(t_stack **head_stack_a, t_stack **head_stack_b, int debug_flag)
{
	t_stack	*tmp;
	t_stack	*new_last;

	write(1, "rrb\n", 4);
	if ((*head_stack_b) == NULL || ((*head_stack_b) && !(*head_stack_b)->next))
	{
		if (debug_flag)
			ft_print_stacks(*head_stack_a, *head_stack_b, "rrb\n");
		return ;
	}
	new_last = (*head_stack_b);
	while (new_last->next->next)
		new_last = new_last->next;
	tmp = new_last->next;
	new_last->next = NULL;
	tmp->next = (*head_stack_b);
	(*head_stack_b) = tmp;
	if (debug_flag)
		ft_print_stacks(*head_stack_a, *head_stack_b, "rrb\n");
}

void	ft_rrr(t_stack **head_stack_a, t_stack **head_stack_b, int debug_flag)
{
	write(1, "rrr\n", 4);
	ft_rra(head_stack_a, head_stack_b, 0);
	ft_rrb(head_stack_b, head_stack_b, 0);
	if (debug_flag)
		ft_print_stacks(*head_stack_a, *head_stack_b, "rrr\n");
}
