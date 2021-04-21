#include "../push_swap.h"

void	ft_sa(t_stack **head_stack_a, t_instr **head_instr)
{
	t_stack	*tmp1;

	if (*head_instr == NULL)
		ft_create_new_instr(head_instr, "sa\n");
	else
		ft_push_back_new_instr(head_instr, "sa\n");
	if ((*head_stack_a == NULL) || ((*head_stack_a) && !(*head_stack_a)->next))
		return ;
	tmp1 = (*head_stack_a);
	(*head_stack_a) = (*head_stack_a)->next;
	tmp1->next = (*head_stack_a)->next;
	(*head_stack_a)->next = tmp1;
}

void	ft_sb(t_stack **head_stack_b, t_instr **head_instr)
{
	t_stack	*tmp1;

	if (*head_instr == NULL)
		ft_create_new_instr(head_instr, "sb\n");
	else
		ft_push_back_new_instr(head_instr, "sb\n");
	if ((*head_stack_b == NULL) || ((*head_stack_b) && !(*head_stack_b)->next))
		return ;
	tmp1 = (*head_stack_b);
	(*head_stack_b) = (*head_stack_b)->next;
	tmp1->next = (*head_stack_b)->next;
	(*head_stack_b)->next = tmp1;
}

void	ft_ss(t_stack **head_stack_a, t_stack **head_stack_b, t_instr **head_instr)
{
	if (*head_instr == NULL)
		ft_create_new_instr(head_instr, "ss\n");
	else
		ft_push_back_new_instr(head_instr, "ss\n");
	ft_sa(head_stack_a, head_instr);
	ft_sb(head_stack_b, head_instr);
}
