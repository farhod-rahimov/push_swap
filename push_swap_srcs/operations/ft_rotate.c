#include "../push_swap.h"

void	ft_ra(t_stack **head_stack_a, t_instr **head_instr)
{
	t_stack	*tmp;
	t_stack	*last;

	if (*head_instr == NULL)
		ft_create_new_instr(head_instr, "ra\n");
	else
		ft_push_back_new_instr(head_instr, "ra\n");
	if ((*head_stack_a) == NULL || ((*head_stack_a) && !(*head_stack_a)->next))
		return ;
	tmp = (*head_stack_a);
	(*head_stack_a) = (*head_stack_a)->next;
	last = (t_stack *)ft_lstlast((t_list *)(*head_stack_a));
	last->next = tmp;
	tmp->next = NULL;
}

void	ft_rb(t_stack **head_stack_b, t_instr **head_instr)
{
	t_stack	*tmp;
	t_stack	*last;

	if (*head_instr == NULL)
		ft_create_new_instr(head_instr, "rb\n");
	else
		ft_push_back_new_instr(head_instr, "rb\n");
	if ((*head_stack_b) == NULL || ((*head_stack_b) && !(*head_stack_b)->next))
		return ;
	tmp = (*head_stack_b);
	(*head_stack_b) = (*head_stack_b)->next;
	last = (t_stack *)ft_lstlast((t_list *)(*head_stack_b));
	last->next = tmp;
	tmp->next = NULL;
}

void	ft_rr(t_stack **head_stack_a, t_stack **head_stack_b, t_instr **head_instr)
{
	if (*head_instr == NULL)
		ft_create_new_instr(head_instr, "rr\n");
	else
		ft_push_back_new_instr(head_instr, "rr\n");
	ft_ra(head_stack_a, head_instr);
	ft_rb(head_stack_b, head_instr);
}
