#include "../push_swap.h"

void	ft_sa(t_stack **head_stack_a, t_instr **head_instr, int write_flag)
{
	t_stack	*tmp1;
	t_instr	*last_instr;

	last_instr = (t_instr *)ft_lstlast((t_list *)(*head_instr));
	if ((*head_instr) && !ft_strcmp(last_instr->str, "sb\n") && write_flag)
	{
		last_instr->str = "ss\n";
		ft_sa(head_stack_a, head_instr, 0);
		return ;
	}
	else if (write_flag)
		ft_push_back_new_instr(head_instr, "sa\n");
	if ((*head_stack_a == NULL) || ((*head_stack_a) && !(*head_stack_a)->next))
		return ;
	tmp1 = (*head_stack_a);
	(*head_stack_a) = (*head_stack_a)->next;
	tmp1->next = (*head_stack_a)->next;
	(*head_stack_a)->next = tmp1;
}

void	ft_sb(t_stack **head_stack_b, t_instr **head_instr, int write_flag)
{
	t_stack	*tmp1;
	t_instr	*last_instr;

	last_instr = (t_instr *)ft_lstlast((t_list *)(*head_instr));
	if ((*head_instr) && !ft_strcmp(last_instr->str, "sa\n") && write_flag)
	{
		last_instr->str = "ss\n";
		ft_sb(head_stack_b, head_instr, 0);
		return ;
	}
	else if (write_flag)
		ft_push_back_new_instr(head_instr, "sb\n");
	if ((*head_stack_b == NULL) || ((*head_stack_b) && !(*head_stack_b)->next))
		return ;
	tmp1 = (*head_stack_b);
	(*head_stack_b) = (*head_stack_b)->next;
	tmp1->next = (*head_stack_b)->next;
	(*head_stack_b)->next = tmp1;
}

void	ft_ss(t_stack **head_stack_a, t_stack **head_stack_b, \
					t_instr **head_instr, int write_flag)
{
	if (write_flag)
		ft_push_back_new_instr(head_instr, "ss\n");
	ft_sa(head_stack_a, head_instr, 0);
	ft_sb(head_stack_b, head_instr, 0);
}
