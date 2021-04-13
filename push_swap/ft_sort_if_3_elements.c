#include "push_swap.h"

int	ft_sort_if_3_elements(t_stack **head, int sorted_a)
{
	int	value_0;
	int	value_1;
	int	value_2;
	// int i;
	int	flag;

	flag = 0;
	value_0 = (*head)->value;
	value_1 = (*head)->next->value;
	value_2 = (*head)->next->next->value;
	if (value_1 < value_2 && value_0 > value_2)
	{
		if (sorted_a == 0)
		{
			flag = 1;
			ft_ra(head);
		}
		else
		{
			flag = 1;
			ft_sa(head);
			ft_ra(head);
			ft_sa(head);
			ft_ra(head);
			ft_ra(head);
		}
	}
	else if (value_1 < value_2 && value_0 > value_1)
	{
		if (sorted_a == 0)
		{
			flag = 1;
			ft_sa(head);
		}
		else
		{
			flag = 1;
			ft_sa(head);
			ft_ra(head);
			ft_ra(head);
			ft_ra(head);
		}
	}
	else if (value_0 > value_1 && value_1 > value_2)
	{
		if (sorted_a == 0)
		{
			flag = 1;
			ft_ra(head);
			ft_sa(head);
		}
		else
		{
			flag = 1;
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
	else if (value_0 < value_1 && value_1 > value_2 && value_0 > value_2)
	{
		if (sorted_a == 0)
		{
			flag = 1;
			ft_rra(head);
		}
		else
		{
			flag = 1;
			ft_ra(head);
			ft_sa(head);
			ft_rra(head);
			ft_sa(head);
			ft_ra(head);
			ft_ra(head);
			ft_ra(head);
		}
	}
	else if (value_0 < value_1 && value_1 > value_2 && value_0 < value_2)
	{
		if (sorted_a == 0)
		{
			flag = 1;
			ft_ra(head);
			ft_sa(head);
			ft_rra(head);
		}
		else
		{
			flag = 1;
			ft_ra(head);
			ft_sa(head);
			ft_ra(head);
			ft_ra(head);
		}
	}
	else if (value_0 < value_1 && value_1 < value_2 && value_0 < value_2)
	{
		if (sorted_a != 0)
		{
			flag = 1;
			ft_ra(head);
			ft_ra(head);
			ft_ra(head);
		}
	}
	return (sorted_a + 3);
}