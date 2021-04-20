#include "../push_swap.h"

void	case_1(t_stack **head_stack_a, t_stack **head_stack_b, int sorted_a)
{
	(void)head_stack_b;
	if (sorted_a == 0)
	{
		ft_rra(head_stack_a);
		ft_sa(head_stack_a);
	}
	else
	{
		ft_ra(head_stack_a);
		ft_sa(head_stack_a);
		ft_ra(head_stack_a);
		ft_ra(head_stack_a);
	}
}

void	case_2(t_stack **head_stack_a, t_stack **head_stack_b, int sorted_a)
{
	(void)head_stack_b;
	if (sorted_a == 0)
	{
		ft_sa(head_stack_a);
	}
	else
	{
		ft_sa(head_stack_a);
		ft_ra(head_stack_a);
		ft_ra(head_stack_a);
		ft_ra(head_stack_a);
	}
}

void	case_3(t_stack **head_stack_a, t_stack **head_stack_b, int sorted_a)
{
	(void)head_stack_b;
	if (sorted_a == 0)
	{
		ft_rra(head_stack_a);
	}
	else
	{
		ft_ra(head_stack_a);
		ft_sa(head_stack_a);
		ft_rra(head_stack_a);
		ft_sa(head_stack_a);
		ft_ra(head_stack_a);
		ft_ra(head_stack_a);
		ft_ra(head_stack_a);
	}
}
