#include "../push_swap.h"

void	ft_ra(t_stack **head_stack_a, t_instr **head_instr, int write_flag)
{
	t_stack	*tmp;
	t_stack	*last;
	t_instr	*last_instr;

	last_instr = (t_instr *)ft_lstlast((t_list *)(*head_instr));
	if ((*head_instr) && !ft_strcmp(last_instr->str, "rb\n") && write_flag)
	{
		last_instr->str = "rr\n";
		ft_ra(head_stack_a, head_instr, 0);
		return ;
	}
	else if (write_flag)
		ft_push_back_new_instr(head_instr, "ra\n");
	if ((*head_stack_a) == NULL || ((*head_stack_a) && !(*head_stack_a)->next))
		return ;
	tmp = (*head_stack_a);
	(*head_stack_a) = (*head_stack_a)->next;
	last = (t_stack *)ft_lstlast((t_list *)(*head_stack_a));
	last->next = tmp;
	tmp->next = NULL;
}

void	ft_rb(t_stack **head_stack_b, t_instr **head_instr, int write_flag)
{
	t_stack	*tmp;
	t_stack	*last;
	t_instr	*last_instr;

	last_instr = (t_instr *)ft_lstlast((t_list *)(*head_instr));
	if ((*head_instr) && !ft_strcmp(last_instr->str, "ra\n") && write_flag)
	{
		last_instr->str = "rr\n";
		ft_rb(head_stack_b, head_instr, 0);
		return ;
	}
	else if (write_flag)
		ft_push_back_new_instr(head_instr, "rb\n");
	if ((*head_stack_b) == NULL || ((*head_stack_b) && !(*head_stack_b)->next))
		return ;
	tmp = (*head_stack_b);
	(*head_stack_b) = (*head_stack_b)->next;
	last = (t_stack *)ft_lstlast((t_list *)(*head_stack_b));
	last->next = tmp;
	tmp->next = NULL;
}

void	ft_rr(t_stack **head_stack_a, t_stack **head_stack_b, t_instr **head_instr, int write_flag)
{
	if (write_flag)
		ft_push_back_new_instr(head_instr, "rr\n");
	ft_ra(head_stack_a, head_instr, 0);
	ft_rb(head_stack_b, head_instr, 0);
}
