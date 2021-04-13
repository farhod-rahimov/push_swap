#include "push_swap.h"

void	ft_trash(t_stack **head_stack_a, t_stack *head_stack_b, int *segment_size);
t_stack    *ft_sort_stack_a(t_stack **head_stack_a, t_stack **head_stack_b, int list_size, int sorted_a);

t_stack    *ft_sort_stack(t_stack **head_stack_a, t_stack *head_stack_b, int list_size, int sorted_a)
{
	ft_sort_stack_a(head_stack_a, &head_stack_b, list_size, sorted_a);
	return (NULL);
}

t_stack    *ft_sort_stack_a(t_stack **head_stack_a, t_stack **head_stack_b, int list_size, int sorted_a)
{
	int	*segment_size;
	int	tmp_segm_size;
	int	median;
	int	i;
	int	k;

	segment_size = (int *)malloc(sizeof(int) * (list_size / 2));
	ft_bzero(segment_size, (list_size / 2) * sizeof(int));
	k = 0;
	while (list_size > 3)
	{
		median = ft_get_median((*head_stack_a), ft_lstsize((t_list *)(*head_stack_a)));
		// printf("median = %d\n", median);
		i = 0;
		tmp_segm_size = ft_lstsize((t_list *)head_stack_b);
		while (i < list_size)
		{
			if ((*head_stack_a)->value > median)
				ft_pb(head_stack_a, &head_stack_b);
			else
				ft_ra(head_stack_a);
			i++;
		}
		segment_size[k++] = ft_lstsize((t_list *)head_stack_b) - tmp_segm_size;
		list_size = ft_lstsize((t_list *)(*head_stack_a));
	}
	// ft_trash(head_stack_a, head_stack_b, segment_size);
	
	if (ft_lstsize((t_list *)(*head_stack_a)) == 2)
		ft_sort_if_2_elements(head_stack_a, 0);
	else if (ft_lstsize((t_list *)(*head_stack_a)) == 3)
		ft_sort_if_3_elements(head_stack_a, 0);
	
	// sorted_a = ft_lstsize((t_list *)(*head_stack_a));
	// printf("sorted_a %d\n", sorted_a);


	// ft_sort_stack_b(head_stack_a, &head_stack_b, segment_size, --k, sorted_a);
	// ft_print((*head_stack_a));
	return(head_stack_b);
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

void	ft_sort_if_3_elements(t_stack **head, int start_segm)
{
	int	value_0;
	int	value_1;
	int	value_2;

	// while ()
	(void)start_segm;
	value_0 = (*head)->value;
	value_1 = (*head)->next->value;
	value_2 = (*head)->next->next->value;

	if (value_1 < value_2 && value_0 > value_2)
		ft_ra(head);
	else if (value_0 < value_2 && value_1 > value_2)
	{
		ft_ra(head);
		ft_sa(head);
		ft_rra(head);
	}
	else if (value_0 > value_1 && value_1 > value_2)
	{
		ft_ra(head);
		ft_sa(head);
	}
	else if (value_0 > value_1 && value_1 < value_2)
	{
		ft_rra(head);
		ft_sa(head);
		ft_rra(head);
	}
	else if (value_0 < value_1 && value_1 > value_2 && value_0 > value_2)
	{
		ft_rra(head);
	}
	else if (value_0 < value_1 && value_1 > value_2 && value_0 < value_2)
	{
		ft_ra(head);
		ft_sa(head);
		ft_rra(head);
	}
}

void	ft_sort_if_2_elements(t_stack **head, int start_segm)
{
	int value_0;
	int value_1;

	(void)start_segm;
	value_0 = (*head)->value;
	value_1 = (*head)->next->value;
	if (value_0 > value_1)
		ft_sa(head);
}