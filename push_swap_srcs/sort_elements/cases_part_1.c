#include "../push_swap.h"

void	case_1(t_stack **head, int sorted_a)
{
	if (sorted_a == 0)
		ft_ra(head);
	else
	{
		ft_sa(head);
		ft_ra(head);
		ft_sa(head);
		ft_ra(head);
		ft_ra(head);
	}
}

void	case_2(t_stack **head, int sorted_a)
{
	if (sorted_a == 0)
		ft_sa(head);
	else
	{
		ft_sa(head);
		ft_ra(head);
		ft_ra(head);
		ft_ra(head);
	}
}

void	case_3(t_stack **head, int sorted_a)
{
	if (sorted_a == 0)
	{
		ft_ra(head);
		ft_sa(head);
	}
	else
	{
		ft_ra(head);
		ft_sa(head);
		ft_rra(head);
		ft_sa(head);
		ft_ra(head);
		ft_sa(head);
		ft_ra(head);
		ft_ra(head);
	}
}
