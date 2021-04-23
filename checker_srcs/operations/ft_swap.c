#include "../checker.h"

void	ft_sa(t_stack **head_stack_a)
{
	t_stack	*tmp1;

	if ((*head_stack_a == NULL) || ((*head_stack_a) && !(*head_stack_a)->next))
		return ;
	tmp1 = (*head_stack_a);
	(*head_stack_a) = (*head_stack_a)->next;
	tmp1->next = (*head_stack_a)->next;
	(*head_stack_a)->next = tmp1;
}

void	ft_sb(t_stack **head_stack_b)
{
	t_stack	*tmp1;

	if ((*head_stack_b == NULL) || ((*head_stack_b) && !(*head_stack_b)->next))
		return ;
	tmp1 = (*head_stack_b);
	(*head_stack_b) = (*head_stack_b)->next;
	tmp1->next = (*head_stack_b)->next;
	(*head_stack_b)->next = tmp1;
}

void	ft_ss(t_stack **head_stack_a, t_stack **head_stack_b)
{
	ft_sa(head_stack_a);
	ft_sb(head_stack_b);
}
