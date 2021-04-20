#include "../push_swap.h"

void	case_1(t_stack **head_stack_a, t_stack **head_stack_b, int sorted_a, int debug_flag)
{
	(void)head_stack_b;
	if (sorted_a == 0)
	{
		ft_rra(head_stack_a, head_stack_b, debug_flag);
		ft_sa(head_stack_a, head_stack_b, debug_flag);
	}
	else
	{
		ft_ra(head_stack_a, head_stack_b, debug_flag);
		ft_sa(head_stack_a, head_stack_b, debug_flag);
		ft_ra(head_stack_a, head_stack_b, debug_flag);
		ft_ra(head_stack_a, head_stack_b, debug_flag);
	}
}

void	case_2(t_stack **head_stack_a, t_stack **head_stack_b, int sorted_a, int debug_flag)
{
	(void)head_stack_b;
	if (sorted_a == 0)
	{
		ft_sa(head_stack_a, head_stack_b, debug_flag);
	}
	else
	{
		ft_sa(head_stack_a, head_stack_b, debug_flag);
		ft_ra(head_stack_a, head_stack_b, debug_flag);
		ft_ra(head_stack_a, head_stack_b, debug_flag);
		ft_ra(head_stack_a, head_stack_b, debug_flag);
	}
}

void	case_3(t_stack **head_stack_a, t_stack **head_stack_b, int sorted_a, int debug_flag)
{
	(void)head_stack_b;
	if (sorted_a == 0)
	{
		ft_rra(head_stack_a, head_stack_b, debug_flag);
	}
	else
	{
		ft_ra(head_stack_a, head_stack_b, debug_flag);
		ft_sa(head_stack_a, head_stack_b, debug_flag);
		ft_rra(head_stack_a, head_stack_b, debug_flag);
		ft_sa(head_stack_a, head_stack_b, debug_flag);
		ft_ra(head_stack_a, head_stack_b, debug_flag);
		ft_ra(head_stack_a, head_stack_b, debug_flag);
		ft_ra(head_stack_a, head_stack_b, debug_flag);
	}
}
