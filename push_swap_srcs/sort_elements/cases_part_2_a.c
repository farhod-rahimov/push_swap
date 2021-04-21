#include "../push_swap.h"

void	case_4_a(t_stack **head_stack_a, t_stack **head_stack_b, int sorted_a, t_instr **head_instr)
{
	(void)head_stack_b;
	if (sorted_a == 0)
	{
		ft_ra(head_stack_a, head_instr, 1);
		ft_sa(head_stack_a, head_instr, 1);
	}
	else
	{
		ft_pb(head_stack_a, head_stack_b, head_instr, 1);
		ft_sa(head_stack_a, head_instr, 1);
		ft_ra(head_stack_a, head_instr, 1);
		ft_ra(head_stack_a, head_instr, 1);
		ft_pa(head_stack_a, head_stack_b, head_instr, 1);
		ft_ra(head_stack_a, head_instr, 1);
	}
}

void	case_5_a(t_stack **head_stack_a, t_stack **head_stack_b, int sorted_a, t_instr **head_instr)
{
	(void)head_stack_b;
	if (sorted_a == 0)
	{
		ft_ra(head_stack_a, head_instr, 1);
	}
	else
	{
		ft_sa(head_stack_a, head_instr, 1);
		ft_ra(head_stack_a, head_instr, 1);
		ft_sa(head_stack_a, head_instr, 1);
		ft_ra(head_stack_a, head_instr, 1);
		ft_ra(head_stack_a, head_instr, 1);
	}
}

void	case_6_a(t_stack **head_stack_a, t_stack **head_stack_b, int sorted_a, t_instr **head_instr)
{
	(void)head_stack_b;
	if (sorted_a == 0)
		;
	else
	{
		ft_ra(head_stack_a, head_instr, 1);
		ft_ra(head_stack_a, head_instr, 1);
		ft_ra(head_stack_a, head_instr, 1);
	}
}
