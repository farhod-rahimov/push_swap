#include "push_swap.h"


int ft_sort_stack_a(t_stack **head_stack_a, t_stack **head_stack_b, int list_size, int sorted_a);

void	ft_sort_stack_main(t_stack **head_stack_a, t_stack *head_stack_b, int list_size, int sorted_a)
{
	int	*array;

	array = ft_create_array_from_list(list_size, (*head_stack_a));
	if (!ft_check_if_stack_is_sorted(array, list_size))
		ft_sort_stack_a(head_stack_a, &head_stack_b, list_size, sorted_a);
	free(array);
}

int	ft_sort_stack_a(t_stack **head_stack_a, t_stack **head_stack_b, int list_size, int sorted_a)
{
	int *array;
	int	*segment_size;
	int	tmp_segm_size;
	int	median;
	int	i;
	int b;
	int	k;

	(void)sorted_a;
	segment_size = (int *)malloc(sizeof(int) * (list_size / 2));
	ft_bzero(segment_size, (list_size / 2) * sizeof(int));
	k = 0;
	while (list_size > 3)
	{
		median = ft_get_median((*head_stack_a), list_size);
		i = 0;
		b = 0;
		tmp_segm_size = ft_lstsize((t_list *)(*head_stack_b));
		while (i < list_size)
		{
			if ((*head_stack_a)->value > median)
				ft_pb(head_stack_a, head_stack_b);
			else
			{
				ft_ra(head_stack_a);
				b++;
			}
			i++;
		}
		while (b-- > 0 && sorted_a > 0)
			ft_rra(head_stack_a);
		segment_size[k++] = ft_lstsize((t_list *)(*head_stack_b)) - tmp_segm_size;
		list_size = ft_lstsize((t_list *)(*head_stack_a)) - sorted_a;
	}
	if (list_size == 2)
		sorted_a = ft_sort_if_2_elements(head_stack_a, sorted_a);
	else if (list_size == 3)
		sorted_a = ft_sort_if_3_elements(head_stack_a, sorted_a);
	while (--k >= 0)
	{
		i = 0;
		if ((*head_stack_b) && ft_lstsize((t_list *)(*head_stack_b)) < 3)
			ft_sort_stack_a(head_stack_b, NULL, ft_lstsize((t_list *)(*head_stack_b)), 0);
		while (i < segment_size[k])
		{
			ft_pa(head_stack_a, head_stack_b);
			i++;
		}
		array = ft_create_array_from_list(segment_size[k], (*head_stack_b));
		if (!ft_check_if_stack_is_sorted(array, segment_size[k]))
			sorted_a = ft_sort_stack_a(head_stack_a, head_stack_b, segment_size[k], sorted_a);
		else
		{
			i = 0;
			while (i < segment_size[k])
			{
				ft_ra(head_stack_a);
				i++;
			}
		}
		free(array);
	}
	free(segment_size);
	return(sorted_a);
}
