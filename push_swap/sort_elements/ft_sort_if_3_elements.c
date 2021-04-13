#include "../push_swap.h"

int	ft_sort_if_3_elements(t_stack **head, int sorted_a)
{
	int	value_0;
	int	value_1;
	int	value_2;

	value_0 = (*head)->value;
	value_1 = (*head)->next->value;
	value_2 = (*head)->next->next->value;
	if (value_1 < value_2 && value_0 > value_2)
		case_1(head, sorted_a);
	else if (value_1 < value_2 && value_0 > value_1)
		case_2(head, sorted_a);
	else if (value_0 > value_1 && value_1 > value_2)
		case_3(head, sorted_a);
	else if (value_0 < value_1 && value_1 > value_2 && value_0 > value_2)
		case_4(head, sorted_a);
	else if (value_0 < value_1 && value_1 > value_2 && value_0 < value_2)
		case_5(head, sorted_a);
	else if (value_0 < value_1 && value_1 < value_2 && value_0 < value_2)
		case_6(head, sorted_a);
	return (sorted_a + 3);
}
