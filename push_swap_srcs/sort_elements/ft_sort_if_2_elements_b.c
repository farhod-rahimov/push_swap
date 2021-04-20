#include "../push_swap.h"

int	ft_sort_if_2_elements_b(t_stack **head, int sorted_a)
{
	int	value_0;
	int	value_1;
	int	i;

	value_0 = (*head)->value;
	value_1 = (*head)->next->value;
	if (value_0 > value_1)
		ft_sb(head);
	i = 0;
	while (i < 2 && sorted_a > 0)
	{
		ft_rb(head);
		i++;
	}
	return (sorted_a + 2);
}
