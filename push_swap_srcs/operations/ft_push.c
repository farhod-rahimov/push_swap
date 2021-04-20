#include "../push_swap.h"

void	ft_pa(t_stack **head_stack_a, t_stack **head_stack_b, int debug_flag)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	write(1, "pa\n", 3);
	if ((*head_stack_b) == NULL)
	{
		if (debug_flag)
			ft_print_stacks(*head_stack_a, *head_stack_b, "pa\n");
		return ;
	}
	tmp1 = (*head_stack_b);
	(*head_stack_b) = (*head_stack_b)->next;
	tmp2 = (*head_stack_a);
	tmp1->next = tmp2;
	(*head_stack_a) = tmp1;
	if (debug_flag)
		ft_print_stacks(*head_stack_a, *head_stack_b, "pa\n");
}

void	ft_pb(t_stack **head_stack_a, t_stack **head_stack_b, int debug_flag)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	write(1, "pb\n", 3);
	if ((*head_stack_a) == NULL)
	{
		if (debug_flag)
			ft_print_stacks(*head_stack_a, *head_stack_b, "pb\n");
		return ;
	}
	tmp1 = (*head_stack_a);
	(*head_stack_a) = (*head_stack_a)->next;
	tmp2 = (*head_stack_b);
	tmp1->next = tmp2;
	(*head_stack_b) = tmp1;
	if (debug_flag)
		ft_print_stacks(*head_stack_a, *head_stack_b, "pb\n");
}
