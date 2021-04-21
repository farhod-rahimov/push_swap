#include "../push_swap.h"

void	ft_pa(t_stack **head_stack_a, t_stack **head_stack_b, t_instr **head_instr, int write_flag)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (write_flag)
		ft_push_back_new_instr(head_instr, "pa\n");
	if ((*head_stack_b) == NULL)
		return ;
	tmp1 = (*head_stack_b);
	(*head_stack_b) = (*head_stack_b)->next;
	tmp2 = (*head_stack_a);
	tmp1->next = tmp2;
	(*head_stack_a) = tmp1;
}

void	ft_pb(t_stack **head_stack_a, t_stack **head_stack_b, t_instr **head_instr, int write_flag)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (write_flag)
		ft_push_back_new_instr(head_instr, "pb\n");
	if ((*head_stack_a) == NULL)
		return ;
	tmp1 = (*head_stack_a);
	(*head_stack_a) = (*head_stack_a)->next;
	tmp2 = (*head_stack_b);
	tmp1->next = tmp2;
	(*head_stack_b) = tmp1;
}
