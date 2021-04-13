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

// void	ft_sort_stack_a_part1(t_stack **head_stack_a, t_stack **head_stack_b, int list_size, int sorted_a)
// {
// 	int	median;
// 	int	i;
// 	int	b;

// 	while (list_size > 3)
// 	{
// 		median = ft_get_median((*head_stack_a), list_size);
// 		i = 0;
// 		b = 0;
// 		tmp_segm_size = ft_lstsize((t_list *)(*head_stack_b));
// 		while (i < list_size)
// 		{
// 			if ((*head_stack_a)->value > median)
// 				ft_pb(head_stack_a, head_stack_b);
// 			else
// 			{
// 				ft_ra(head_stack_a);
// 				b++;
// 			}
// 			i++;
// 		}
// 		while (b-- > 0 && sorted_a > 0)
// 			ft_rra(head_stack_a);
// 		strct.segment_size[k++] = ft_lstsize((t_list *)(*head_stack_b)) - tmp_segm_size;
// 		list_size = ft_lstsize((t_list *)(*head_stack_a)) - sorted_a;
// 	}
// }

int	ft_sort_stack_a(t_stack **head_stack_a, t_stack **head_stack_b, int list_size, int sorted_a)
{
	t_sort strct;
	int	*array;
	// int	*segment_size;
	int	tmp_segm_size;
	int	median;
	int	i;
	int	b;
	int	k;

	// segment_size = (int *)malloc(sizeof(int) * (list_size / 2));
	strct.head_stack_a = head_stack_a;
	strct.head_stack_b = head_stack_b;
	strct.list_size = list_size;
	strct.sorted_a = sorted_a;
	strct.segment_size = ft_create_blank_array(list_size / 2);
	ft_bzero(strct.segment_size, (list_size / 2) * sizeof(int));
	k = 0;
	while (list_size > 3)
	{
		median = ft_get_median((*strct.head_stack_a), list_size);
		i = 0;
		b = 0;
		tmp_segm_size = ft_lstsize((t_list *)(*strct.head_stack_b));
		while (i < list_size)
		{
			if ((*strct.head_stack_a)->value > median)
				ft_pb(strct.head_stack_a, strct.head_stack_b);
			else
			{
				ft_ra(strct.head_stack_a);
				b++;
			}
			i++;
		}
		while (b-- > 0 && strct.sorted_a > 0)
			ft_rra(strct.head_stack_a);
		strct.segment_size[k++] = ft_lstsize((t_list *)(*strct.head_stack_b)) - tmp_segm_size;
		list_size = ft_lstsize((t_list *)(*strct.head_stack_a)) - strct.sorted_a;
	}
	if (list_size == 2)
		strct.sorted_a = ft_sort_if_2_elements(strct.head_stack_a, strct.sorted_a);
	else if (list_size == 3)
		strct.sorted_a = ft_sort_if_3_elements(strct.head_stack_a, strct.sorted_a);
	while (--k >= 0)
	{
		i = 0;
		if ((*strct.head_stack_b) && ft_lstsize((t_list *)(*strct.head_stack_b)) < 3)
			ft_sort_stack_a(strct.head_stack_b, NULL, ft_lstsize((t_list *)(*strct.head_stack_b)), 0);
		while (i < strct.segment_size[k])
		{
			ft_pa(strct.head_stack_a, strct.head_stack_b);
			i++;
		}
		array = ft_create_array_from_list(strct.segment_size[k], (*strct.head_stack_b));
		if (!ft_check_if_stack_is_sorted(array, strct.segment_size[k]))
			strct.sorted_a = ft_sort_stack_a(strct.head_stack_a, strct.head_stack_b, strct.segment_size[k], strct.sorted_a);
		else
		{
			i = 0;
			while (i < strct.segment_size[k])
			{
				ft_ra(strct.head_stack_a);
				i++;
			}
		}
		free(array);
	}
	free(strct.segment_size);
	return(strct.sorted_a);
}
