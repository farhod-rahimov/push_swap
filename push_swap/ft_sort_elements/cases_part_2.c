#include "../push_swap.h"

void	case_4(t_stack **head, int sorted_a)
{
	if (sorted_a == 0)
		ft_rra(head);
	else
	{
		ft_ra(head);
		ft_sa(head);
		ft_rra(head);
		ft_sa(head);
		ft_ra(head);
		ft_ra(head);
		ft_ra(head);
	}
}

void	case_5(t_stack **head, int sorted_a)
{
	if (sorted_a == 0)
	{
		ft_ra(head);
		ft_sa(head);
		ft_rra(head);
	}
	else
	{
		ft_ra(head);
		ft_sa(head);
		ft_ra(head);
		ft_ra(head);
	}
}

void	case_6(t_stack **head, int sorted_a)
{
	if (sorted_a != 0)
	{
		ft_ra(head);
		ft_ra(head);
		ft_ra(head);
	}
}
