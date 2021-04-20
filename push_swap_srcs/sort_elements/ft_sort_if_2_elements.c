#include "../push_swap.h"

int	ft_sort_if_2_elements(t_stack **head_stack_a, t_stack **head_stack_b, int sorted_a, int debug_flag)
{
	int	value_0;
	int	value_1;
	int	i;

	value_0 = (*head_stack_a)->value;
	value_1 = (*head_stack_a)->next->value;
	if (value_0 > value_1)
		ft_sa(head_stack_a, head_stack_b, debug_flag);
	i = 0;
	while (i < 2 && sorted_a > 0)
	{
		ft_ra(head_stack_a, head_stack_b, debug_flag);
		i++;
	}
	return (sorted_a + 2);
}
