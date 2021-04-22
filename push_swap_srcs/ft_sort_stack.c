#include "push_swap.h"

t_instr	*ft_sort_stack_main(t_stack **head_stack_a, \
		t_stack *head_stack_b, int list_size, int sorted_a)
{
	t_sort	s;
	t_instr	*head_instr;
	int		*array;

	head_instr = NULL;
	s.head_stack_a = head_stack_a;
	s.head_instr = &head_instr;
	array = ft_create_array_from_list(list_size, (*head_stack_a));
	if (list_size == 2 && !ft_check_if_stack_is_sorted(array, list_size))
		ft_sort_if_2_elements_a(head_stack_a, 0, &head_instr);
	else if (list_size == 3 && !ft_check_if_stack_is_sorted(array, list_size))
		ft_sort_if_3_elements_a(head_stack_a, &head_stack_b, 0, &head_instr);
	else if (list_size <= 5 && !ft_check_if_stack_is_sorted(array, list_size))
		ft_sort_5_elements(head_stack_a, &head_stack_b, &head_instr, list_size);
	else if (!ft_check_if_stack_is_sorted(array, list_size))
		ft_sort_stack_a(&s, &head_stack_b, list_size, sorted_a);
	free(array);
	return (head_instr);
}

static	int	ft_sort_stack_a_part1(t_sort *s, int k, int i, int b)
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
				ft_pb(s->head_stack_a, s->head_stack_b, s->head_instr, 1);
			else
			{
				ft_ra(s->head_stack_a, s->head_instr, 1);
				b++;
			}
		}
		while (b-- > 0 && s->sorted_a > 0)
			ft_rra(s->head_stack_a, s->head_instr, 1);
		s->segm_size[k++] = ft_lstsize((t_list *)(*s->head_stack_b)) - tmp;
		s->list_size = ft_lstsize((t_list *)(*s->head_stack_a)) - s->sorted_a;
	}
	return (k);
}

static	int	part2_helper(t_sort *s, int i, int b, int k)
{
	int	median;

	if ((*s->head_stack_b) && ft_lstsize((t_list *)(*s->head_stack_b)) < 3)
	{
		if (ft_lstsize((t_list *)(*s->head_stack_b)) == 3)
			ft_sort_if_3_elements_b(s->head_stack_a, \
						s->head_stack_b, 0, s->head_instr);
		else if (ft_lstsize((t_list *)(*s->head_stack_b)) == 2)
			ft_sort_if_2_elements_b(s->head_stack_b, 0, s->head_instr);
	}
	median = ft_get_median(*s->head_stack_b, s->segm_size[k]);
	while (i < s->segm_size[k])
	{
		if ((*s->head_stack_b)->value <= median)
			ft_pa(s->head_stack_a, s->head_stack_b, s->head_instr, 1);
		else
		{
			ft_rb(s->head_stack_b, s->head_instr, 1);
			b++;
		}
		i++;
	}
	return (b);
}

static	void	ft_sort_stack_a_part2(t_sort *s, int k, int i, int b)
{
	int	*array;
	int	tmp_b;

	b = part2_helper(s, 0, 0, k);
	tmp_b = b;
	while (tmp_b-- > 0)
		ft_rrb(s->head_stack_b, s->head_instr, 1);
	array = ft_create_array_from_list(s->segm_size[k] - b, (*s->head_stack_a));
	if (!ft_check_if_stack_is_sorted(array, s->segm_size[k] - b))
		s->sorted_a = ft_sort_stack_a(s, s->head_stack_b, \
				s->segm_size[k] - b, s->sorted_a);
	else
	{
		i = 0;
		while (i < s->segm_size[k] - b)
		{
			ft_ra(s->head_stack_a, s->head_instr, 1);
			i++;
		}
		s->sorted_a += i;
	}
	free(array);
	s->segm_size[k] = b;
	if (b)
		ft_sort_stack_a_part2(s, k, 0, 0);
}

int	ft_sort_stack_a(t_sort *s, \
		t_stack **head_stack_b, int list_size, int sorted_a)
{
	t_sort	ss;
	int		k;

	ss.head_stack_a = s->head_stack_a;
	ss.head_instr = s->head_instr;
	ss.head_stack_b = head_stack_b;
	ss.list_size = list_size;
	ss.sorted_a = sorted_a;
	ss.segm_size = ft_create_blank_array(ss.list_size / 2);
	ft_bzero(ss.segm_size, (ss.list_size / 2) * sizeof(int));
	k = ft_sort_stack_a_part1(&ss, 0, 0, 0);
	if (ss.list_size == 2)
		ss.sorted_a = ft_sort_if_2_elements_a(ss.head_stack_a, \
									ss.sorted_a, ss.head_instr);
	else if (ss.list_size == 3)
		ss.sorted_a = ft_sort_if_3_elements_a(ss.head_stack_a, \
					ss.head_stack_b, ss.sorted_a, ss.head_instr);
	while (--k >= 0)
		ft_sort_stack_a_part2(&ss, k, 0, 0);
	free(ss.segm_size);
	return (ss.sorted_a);
}
