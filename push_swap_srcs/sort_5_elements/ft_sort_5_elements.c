#include "../push_swap.h"

void	ft_sort_5_elements(t_stack **head_stack_a, t_stack **head_stack_b, \
						t_instr **head_instr, int list_size)
{
	int	median;
	int	i;

	median = ft_get_median(*head_stack_a, list_size);
	i = 0;
	while (i < list_size)
	{
		if ((*head_stack_a)->value <= median)
			ft_pb(head_stack_a, head_stack_b, head_instr, 1);
		else
			ft_ra(head_stack_a, head_instr, 1);
		i++;
	}
	if (ft_lstsize((t_list *)(*head_stack_a)) == 3)
		ft_sort_if_3_elements_a(head_stack_a, head_stack_b, 0, head_instr);
	else if (ft_lstsize((t_list *)(*head_stack_a)) == 2)
		ft_sort_if_2_elements_a(head_stack_a, 0, head_instr);
	if (ft_lstsize((t_list *)(*head_stack_b)) == 3)
		ft_sort_3_elements_b(head_stack_b, head_instr);
	else if (ft_lstsize((t_list *)(*head_stack_b)) == 2)
		ft_sort_2_elements_b(head_stack_b, head_instr);
	while (*head_stack_b)
		ft_pa(head_stack_a, head_stack_b, head_instr, 1);
}

void	ft_sort_2_elements_b(t_stack **head_stack_b, t_instr **head_instr)
{
	int	value_0;
	int	value_1;

	value_0 = (*head_stack_b)->value;
	value_1 = (*head_stack_b)->next->value;
	if (value_0 < value_1)
		ft_sb(head_stack_b, head_instr, 1);
}

void	ft_sort_3_elements_b(t_stack **head_stack_b, t_instr **head_instr)
{
	int	value_0;
	int	value_1;
	int	value_2;

	value_0 = (*head_stack_b)->value;
	value_1 = (*head_stack_b)->next->value;
	value_2 = (*head_stack_b)->next->next->value;
	if (value_0 < value_1 && value_1 > value_2 && value_0 < value_2)
		case_1(head_stack_b, head_instr);
	else if (value_0 > value_1 && value_1 < value_2 && value_0 < value_2)
		case_2(head_stack_b, head_instr);
	else if (value_0 < value_1 && value_1 > value_2 && value_0 > value_2)
		case_3(head_stack_b, head_instr);
	else if (value_0 > value_1 && value_1 > value_2 && value_0 > value_2)
		;
	else if (value_0 > value_1 && value_1 < value_2 && value_0 > value_2)
		case_5(head_stack_b, head_instr);
	else if (value_0 < value_1 && value_1 < value_2 && value_0 < value_2)
		case_6(head_stack_b, head_instr);
}
