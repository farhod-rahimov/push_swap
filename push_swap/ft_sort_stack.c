#include "push_swap.h"

void	ft_sort_stack_main(t_stack **head_stack_a, \
		t_stack *head_stack_b, int list_size, int sorted_a)
{
	int	*array;

	array = ft_create_array_from_list(list_size, (*head_stack_a));
	if (!ft_check_if_stack_is_sorted(array, list_size))
		ft_sort_stack_a(head_stack_a, &head_stack_b, list_size, sorted_a);
	free(array);
}

int	ft_sort_stack_a_part1(t_sort *s, int k, int i, int b)
{
	int	median;
	int	tmp;

	while (s->list_size > 3)
	{
		i = 0;
		b = 0;
		median = ft_get_median((*s->head_stack_a), s->list_size);
		tmp = ft_lstsize((t_list *)(*s->head_stack_b));
		while (i++ < s->list_size)
		{
			if ((*s->head_stack_a)->value > median)
				ft_pb(s->head_stack_a, s->head_stack_b);
			else
			{
				ft_ra(s->head_stack_a);
				b++;
			}
		}
		while (b-- > 0 && s->sorted_a > 0)
			ft_rra(s->head_stack_a);
		s->segm_size[k++] = ft_lstsize((t_list *)(*s->head_stack_b)) - tmp;
		s->list_size = ft_lstsize((t_list *)(*s->head_stack_a)) - s->sorted_a;
	}
	return (k);
}

void	ft_sort_stack_a_part2(t_sort *s, int k, int i)
{
	int	*array;

	// if ((*s->head_stack_b) && ft_lstsize((t_list *)(*s->head_stack_b)) < 3)
	// 	ft_sort_stack_a(s->head_stack_b, NULL, \
	// 				ft_lstsize((t_list *)(*s->head_stack_b)), 0);
	// printf("E3 "); ft_print(*s->head_stack_a);
	while (i < s->segm_size[k])
	{
		ft_pa(s->head_stack_a, s->head_stack_b);
		i++;
	}
	// printf("E4 "); ft_print(*s->head_stack_a);
	array = ft_create_array_from_list(s->segm_size[k], (*s->head_stack_a)); //b bud
	// printf("array %d\n", array[0]);
	if (!ft_check_if_stack_is_sorted(array, s->segm_size[k]))
		s->sorted_a = ft_sort_stack_a(s->head_stack_a, \
		s->head_stack_b, s->segm_size[k], s->sorted_a);
	else
	{
		// printf("E5 "); ft_print(*s->head_stack_a);
		i = 0;
		while (i < s->segm_size[k])
		{
			ft_ra(s->head_stack_a);
			i++;
		}
		s->sorted_a += i;
	}
	// printf("E6 "); ft_print(*s->head_stack_a);
	free(array);
}

int	ft_sort_stack_a(t_stack **head_stack_a, \
		t_stack **head_stack_b, int list_size, int sorted_a)
{
	t_sort	s;
	int		k;

	s.head_stack_a = head_stack_a;
	s.head_stack_b = head_stack_b;
	s.list_size = list_size;
	s.sorted_a = sorted_a;
	s.segm_size = ft_create_blank_array(s.list_size / 2);
	ft_bzero(s.segm_size, (s.list_size / 2) * sizeof(int));
	// printf("A "); ft_print(*head_stack_a);
	k = ft_sort_stack_a_part1(&s, 0, 0, 0);
	// printf("B "); ft_print(*head_stack_a);
	if (s.list_size == 2)
		s.sorted_a = ft_sort_if_2_elements(s.head_stack_a, \
										s.sorted_a);
	else if (s.list_size == 3)
		s.sorted_a = ft_sort_if_3_elements(s.head_stack_a, \
										s.sorted_a);
	// printf("C "); ft_print(*head_stack_a);
	while (--k >= 0)
	{
		// printf("E1 "); ft_print(*head_stack_a);
		ft_sort_stack_a_part2(&s, k, 0);
		// printf("E2 "); ft_print(*head_stack_a);
	}
	// printf("D "); ft_print(*head_stack_a);
	free(s.segm_size);
	return (s.sorted_a);
}
