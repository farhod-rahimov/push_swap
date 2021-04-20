#include "../push_swap.h"

int	ft_sort_if_3_elements_a(t_stack **head_stack_a, t_stack **head_stack_b, int sorted_a)
{
	int	value_0;
	int	value_1;
	int	value_2;

	value_0 = (*head_stack_a)->value;
	value_1 = (*head_stack_a)->next->value;
	value_2 = (*head_stack_a)->next->next->value;
	if (value_0 < value_1 && value_1 > value_2 && value_0 < value_2)
		case_1_a(head_stack_a, head_stack_b, sorted_a);
	else if (value_0 > value_1 && value_1 < value_2 && value_0 < value_2)
		case_2_a(head_stack_a, head_stack_b, sorted_a);
	else if (value_0 < value_1 && value_1 > value_2 && value_0 > value_2)
		case_3_a(head_stack_a, head_stack_b, sorted_a);
	else if (value_0 > value_1 && value_1 > value_2 && value_0 > value_2)
		case_4_a(head_stack_a, head_stack_b, sorted_a);
	else if (value_0 > value_1 && value_1 < value_2 && value_0 > value_2)
		case_5_a(head_stack_a, head_stack_b, sorted_a);
	else if (value_0 < value_1 && value_1 < value_2 && value_0 < value_2)
		case_6_a(head_stack_a, head_stack_b, sorted_a);
	return (sorted_a + 3);
}
