#include "../push_swap.h"

void	ft_rra(t_stack **head_stack_a, t_instr **head_instr)
{
	t_stack	*tmp;
	t_stack	*new_last;

	if (*head_instr == NULL)
		ft_create_new_instr(head_instr, "rra\n");
	else
		ft_push_back_new_instr(head_instr, "rra\n");
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

void	ft_rrb(t_stack **head_stack_b, t_instr **head_instr)
{
	t_stack	*tmp;
	t_stack	*new_last;

	if (*head_instr == NULL)
		ft_create_new_instr(head_instr, "rrb\n");
	else
		ft_push_back_new_instr(head_instr, "rrb\n");
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

void	ft_rrr(t_stack **head_stack_a, t_stack **head_stack_b, t_instr **head_instr)
{
	if (*head_instr == NULL)
		ft_create_new_instr(head_instr, "rrr\n");
	else
		ft_push_back_new_instr(head_instr, "rrr\n");
	ft_rra(head_stack_a, head_instr);
	ft_rrb(head_stack_b, head_instr);
}
