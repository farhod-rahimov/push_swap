#include "push_swap.h"

void	ft_get_stack_data(t_stack *head_stack_a, char **argv, int i)
{
	t_stack	*current;

	ft_check_if_args_are_int(argv, i);
	current = head_stack_a;
	current->value = ft_atoi(argv[i++]);
	while (argv[i])
		current = ft_push_back_list(current, ft_atoi(argv[i++]));
	ft_check_duplicates_main(head_stack_a);
}

void	ft_check_if_args_are_int(char **argv, int i)
{
	size_t	k;

	k = 0;
	while (argv[i])
	{
		if (argv[i][0] == '-' || argv[i][0] == '+')
			k++;
		while (argv[i][k])
		{
			if (!ft_isdigit(argv[i][k++]))
				ft_error(ERROR);
		}
		k = 0;
		i++;
	}
}

void	ft_check_duplicates_main(t_stack *head_stack_a)
{
	t_stack	*tmp;
	size_t	size;
	int		*array;
	size_t	i;

	tmp = head_stack_a;
	size = ft_lstsize((t_list *)head_stack_a);
	array = (int *)malloc(sizeof(int) * size);
	if (array == NULL)
		ft_error(ERROR);
	i = 0;
	while (tmp)
	{
		array[i] = tmp->value;
		ft_check_duplicates(array, i, array[i]);
		i++;
		tmp = tmp->next;
	}
	//free//(array);
}

void	ft_check_duplicates(int *array, size_t size, int value_check)
{
	size_t	i;
	int		num_duplicates;

	i = 0;
	num_duplicates = 0;
	while (i <= size)
	{
		if (array[i] == value_check)
			if (++num_duplicates > 1)
				ft_error(ERROR);
		i++;
	}
}
