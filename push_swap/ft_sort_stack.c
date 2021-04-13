#include "push_swap.h"

void	ft_trash(t_stack **head_stack_a, t_stack *head_stack_b, int *segment_size);
int ft_sort_stack_a(t_stack **head_stack_a, t_stack **head_stack_b, int list_size, int sorted_a);

t_stack    *ft_sort_stack(t_stack **head_stack_a, t_stack *head_stack_b, int list_size, int sorted_a)
{
	int *array;
	array = ft_create_array_from_list(list_size, (*head_stack_a));
	if (!ft_check_if_stack_is_sorted(array, list_size))
		ft_sort_stack_a(head_stack_a, &head_stack_b, list_size, sorted_a);
	free(array);
	return (NULL);
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

void	ft_trash(t_stack **head_stack_a, t_stack *head_stack_b, int *segment_size)
{
	int k;

	ft_print((*head_stack_a));
	printf("\n----------\n");
	ft_print(head_stack_b);
	printf("\n");
	k = 0;
	while (segment_size[k])
		printf("s[k] %d ", segment_size[k++]);
	printf("\n");
}

int	ft_sort_if_3_elements(t_stack **head, int sorted_a)
{
	int	value_0;
	int	value_1;
	int	value_2;
	// int i;
	int	flag;

	flag = 0;
	value_0 = (*head)->value;
	value_1 = (*head)->next->value;
	value_2 = (*head)->next->next->value;
	if (value_1 < value_2 && value_0 > value_2)
	{
		if (sorted_a == 0)
		{
			flag = 1;
			ft_ra(head);
		}
		else
		{
			flag = 1;
			ft_sa(head);
			ft_ra(head);
			ft_sa(head);
			ft_ra(head);
			ft_ra(head);
		}
	}
	else if (value_1 < value_2 && value_0 > value_1)
	{
		if (sorted_a == 0)
		{
			flag = 1;
			ft_sa(head);
		}
		else
		{
			flag = 1;
			ft_sa(head);
			ft_ra(head);
			ft_ra(head);
			ft_ra(head);
		}
	}
	else if (value_0 > value_1 && value_1 > value_2)
	{
		if (sorted_a == 0)
		{
			flag = 1;
			ft_ra(head);
			ft_sa(head);
		}
		else
		{
			flag = 1;
			ft_ra(head);
			ft_sa(head);
			ft_rra(head);
			ft_sa(head);
			ft_ra(head);
			ft_sa(head);
			ft_ra(head);
			ft_ra(head);
		}
	}
	else if (value_0 < value_1 && value_1 > value_2 && value_0 > value_2)
	{
		if (sorted_a == 0)
		{
			flag = 1;
			ft_rra(head);
		}
		else
		{
			flag = 1;
			ft_ra(head);
			ft_sa(head);
			ft_rra(head);
			ft_sa(head);
			ft_ra(head);
			ft_ra(head);
			ft_ra(head);
		}
	}
	else if (value_0 < value_1 && value_1 > value_2 && value_0 < value_2)
	{
		if (sorted_a == 0)
		{
			flag = 1;
			ft_ra(head);
			ft_sa(head);
			ft_rra(head);
		}
		else
		{
			flag = 1;
			ft_ra(head);
			ft_sa(head);
			ft_ra(head);
			ft_ra(head);
		}
	}
	else if (value_0 < value_1 && value_1 < value_2 && value_0 < value_2)
	{
		if (sorted_a != 0)
		{
			flag = 1;
			ft_ra(head);
			ft_ra(head);
			ft_ra(head);
		}
	}
	return (sorted_a + 3);
}

int	ft_sort_if_2_elements(t_stack **head, int sorted_a)
{
	int value_0;
	int value_1;
	int i;

	(void)sorted_a;
	(void)i;
	value_0 = (*head)->value;
	value_1 = (*head)->next->value;
	if (value_0 > value_1)
		ft_sa(head);
	i = 0;
	while (i < 2 && sorted_a > 0)
	{
		ft_ra(head);
		i++;
	}
	return (sorted_a + 2);
}