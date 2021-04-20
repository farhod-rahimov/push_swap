#include "../push_swap.h"

void	ft_sa(t_stack **head_stack_a, t_stack **head_stack_b, int debug_flag)
{
	t_stack	*tmp1;

	write(1, "sa\n", 3);
	if ((*head_stack_a == NULL) || ((*head_stack_a) && !(*head_stack_a)->next))
	{
		if (debug_flag)
			ft_print_stacks(*head_stack_a, *head_stack_b, "sa\n");
		return ;
	}
	tmp1 = (*head_stack_a);
	(*head_stack_a) = (*head_stack_a)->next;
	tmp1->next = (*head_stack_a)->next;
	(*head_stack_a)->next = tmp1;
	if (debug_flag)
		ft_print_stacks(*head_stack_a, *head_stack_b, "sa\n");
}

void	ft_sb(t_stack **head_stack_a, t_stack **head_stack_b, int debug_flag)
{
	t_stack	*tmp1;

	write(1, "sb\n", 3);
	if ((*head_stack_b == NULL) || ((*head_stack_b) && !(*head_stack_b)->next))
	{
		if (debug_flag)
			ft_print_stacks(*head_stack_a, *head_stack_b, "sb\n");
		return ;
	}
	tmp1 = (*head_stack_b);
	(*head_stack_b) = (*head_stack_b)->next;
	tmp1->next = (*head_stack_b)->next;
	(*head_stack_b)->next = tmp1;
	if (debug_flag)
		ft_print_stacks(*head_stack_a, *head_stack_b, "sb\n");
}

void	ft_ss(t_stack **head_stack_a, t_stack **head_stack_b, int debug_flag)
{
	write(1, "ss\n", 3);
	ft_sa(head_stack_a, head_stack_b, 0);
	ft_sb(head_stack_a, head_stack_b, 0);
	if (debug_flag)
		ft_print_stacks(*head_stack_a, *head_stack_b, "ss\n");
}
