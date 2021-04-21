#include "../push_swap.h"

void	case_1_a(t_stack **head_stack_a, t_stack **head_stack_b, int sorted_a, t_instr **head_instr)
{
	(void)head_stack_b;
	if (sorted_a == 0)
	{
		ft_rra(head_stack_a, head_instr);
		ft_sa(head_stack_a, head_instr);
	}
	else
	{
		ft_ra(head_stack_a, head_instr);
		ft_sa(head_stack_a, head_instr);
		ft_ra(head_stack_a, head_instr);
		ft_ra(head_stack_a, head_instr);
	}
}

void	case_2_a(t_stack **head_stack_a, t_stack **head_stack_b, int sorted_a, t_instr **head_instr)
{
	(void)head_stack_b;
	if (sorted_a == 0)
	{
		ft_sa(head_stack_a, head_instr);
	}
	else
	{
		ft_sa(head_stack_a, head_instr);
		ft_ra(head_stack_a, head_instr);
		ft_ra(head_stack_a, head_instr);
		ft_ra(head_stack_a, head_instr);
	}
}

void	case_3_a(t_stack **head_stack_a, t_stack **head_stack_b, int sorted_a, t_instr **head_instr)
{
	(void)head_stack_b;
	if (sorted_a == 0)
	{
		ft_rra(head_stack_a, head_instr);
	}
	else
	{
		ft_ra(head_stack_a, head_instr);
		ft_sa(head_stack_a, head_instr);
		ft_rra(head_stack_a, head_instr);
		ft_sa(head_stack_a, head_instr);
		ft_ra(head_stack_a, head_instr);
		ft_ra(head_stack_a, head_instr);
		ft_ra(head_stack_a, head_instr);
	}
}
