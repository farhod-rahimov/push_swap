#include "../push_swap.h"

void	case_4_a(t_stack **head_stack_a, t_stack **head_stack_b, int sorted_a)
{
	(void)head_stack_b;
	if (sorted_a == 0)
	{
		ft_ra(head_stack_a);
		ft_sa(head_stack_a);
	}
	else
	{
		ft_pb(head_stack_a, head_stack_b);
		ft_sa(head_stack_a);
		ft_ra(head_stack_a);
		ft_ra(head_stack_a);
		ft_pa(head_stack_a, head_stack_b);
		ft_ra(head_stack_a);
	}
}

void	case_5_a(t_stack **head_stack_a, t_stack **head_stack_b, int sorted_a)
{
	(void)head_stack_b;
	if (sorted_a == 0)
	{
		ft_ra(head_stack_a);
	}
	else
	{
		ft_sa(head_stack_a);
		ft_ra(head_stack_a);
		ft_sa(head_stack_a);
		ft_ra(head_stack_a);
		ft_ra(head_stack_a);
	}
}

void	case_6_a(t_stack **head_stack_a, t_stack **head_stack_b, int sorted_a)
{
	(void)head_stack_b;
	if (sorted_a == 0)
		;
	else
	{
		ft_ra(head_stack_a);
		ft_ra(head_stack_a);
		ft_ra(head_stack_a);
	}
}

// void	case_4(t_stack **head, int sorted_a)
// {
// 	if (sorted_a == 0)
// 		ft_rra(head);
// 	else
// 	{
// 		ft_ra(head);
// 		ft_sa(head);
// 		ft_rra(head);
// 		ft_sa(head);
// 		ft_ra(head);
// 		ft_ra(head);
// 		ft_ra(head);
// 	}
// }

// void	case_5(t_stack **head, int sorted_a)
// {
// 	if (sorted_a == 0)
// 	{
// 		ft_ra(head);
// 		ft_sa(head);
// 		ft_rra(head);
// 	}
// 	else
// 	{
// 		ft_ra(head);
// 		ft_sa(head);
// 		ft_ra(head);
// 		ft_ra(head);
// 	}
// }

// void	case_6(t_stack **head, int sorted_a)
// {
// 	if (sorted_a != 0)
// 	{
// 		ft_ra(head);
// 		ft_ra(head);
// 		ft_ra(head);
// 	}
// }
