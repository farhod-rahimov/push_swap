#include "../push_swap.h"

void	case_4(t_stack **head_stack_a, t_stack **head_stack_b, int sorted_a, int debug_flag)
{
	(void)head_stack_b;
	if (sorted_a == 0)
	{
		ft_ra(head_stack_a, head_stack_b, debug_flag);
		ft_sa(head_stack_a, head_stack_b, debug_flag);
	}
	else
	{
		ft_pb(head_stack_a, head_stack_b, debug_flag);
		ft_sa(head_stack_a, head_stack_b, debug_flag);
		ft_ra(head_stack_a, head_stack_b, debug_flag);
		ft_ra(head_stack_a, head_stack_b, debug_flag);
		ft_pa(head_stack_a, head_stack_b, debug_flag);
		ft_ra(head_stack_a, head_stack_b, debug_flag);
	}
}

void	case_5(t_stack **head_stack_a, t_stack **head_stack_b, int sorted_a, int debug_flag)
{
	(void)head_stack_b;
	if (sorted_a == 0)
	{
		ft_ra(head_stack_a, head_stack_b, debug_flag);
	}
	else
	{
		ft_sa(head_stack_a, head_stack_b, debug_flag);
		ft_ra(head_stack_a, head_stack_b, debug_flag);
		ft_sa(head_stack_a, head_stack_b, debug_flag);
		ft_ra(head_stack_a, head_stack_b, debug_flag);
		ft_ra(head_stack_a, head_stack_b, debug_flag);
	}
}

void	case_6(t_stack **head_stack_a, t_stack **head_stack_b, int sorted_a, int debug_flag)
{
	(void)head_stack_b;
	if (sorted_a == 0)
		;
	else
	{
		ft_ra(head_stack_a, head_stack_b, debug_flag);
		ft_ra(head_stack_a, head_stack_b, debug_flag);
		ft_ra(head_stack_a, head_stack_b, debug_flag);
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
