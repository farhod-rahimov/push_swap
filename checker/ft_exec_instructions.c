#include "checker.h"

void    ft_exec_instructions(t_instr *head_instr, t_stack **head_stack_a)
{
	t_instr *tmp_instr;
	t_stack *head_stack_b;

	tmp_instr = head_instr;
	head_stack_b = NULL;
	printf("\n");
	while (tmp_instr && tmp_instr->str[0])
	{
		if (!ft_strcmp(tmp_instr->str, "sa\n"))
			ft_sa(head_stack_a);
		else if (!ft_strcmp(tmp_instr->str, "sb\n"))
			ft_sb(&head_stack_b);
		else if (!ft_strcmp(tmp_instr->str, "ss\n"))
			ft_ss(head_stack_a, &head_stack_b);
		else if (!ft_strcmp(tmp_instr->str, "pa\n"))
			ft_pa(head_stack_a, &head_stack_b);
		else if (!ft_strcmp(tmp_instr->str, "pb\n"))
			ft_pb(head_stack_a, &head_stack_b);
		else if (!ft_strcmp(tmp_instr->str, "ra\n"))
			ft_ra(head_stack_a);
		else if (!ft_strcmp(tmp_instr->str, "rb\n"))
			ft_rb(&head_stack_b);
		else if (!ft_strcmp(tmp_instr->str, "rr\n"))
			ft_rr(head_stack_a, &head_stack_b);
		else if (!ft_strcmp(tmp_instr->str, "rra\n"))
			ft_rra(head_stack_a);
		else if (!ft_strcmp(tmp_instr->str, "rrb\n"))
			ft_rrb(&head_stack_b);
		else if (!ft_strcmp(tmp_instr->str, "rrr\n"))
			ft_rrr(head_stack_a, &head_stack_b);
		// printf("STACK A\n");
		// ft_print(*head_stack_a);
		// printf("\n-----------\n");
		// printf("STACK B\n");
		// ft_print(head_stack_b);
		// printf("\n-----------\n");
		tmp_instr = tmp_instr->next;
	}
	ft_free_instr(head_instr);
	if (head_stack_b)
		ft_end_programm("KO\n");
}