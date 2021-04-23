#include "checker.h"

static	int	*ft_create_array(t_stack *head)
{
	int	*array;
	int	list_size;
	int	i;

	list_size = ft_lstsize((t_list *)head);
	array = (int *)malloc(sizeof(int) * list_size);
	if (!array)
		ft_error(ERROR);
	i = 0;
	while (head)
	{
		array[i++] = head->value;
		head = head->next;
	}
	return (array);
}

void	ft_check_if_stack_is_sorted(t_stack *head)
{
	int	*array;
	int	list_size;
	int	k;
	int	i;

	array = ft_create_array(head);
	list_size = ft_lstsize((t_list *)head);
	if (list_size == 1)
		ft_end_programm("OK\n");
	k = 1;
	while (k < list_size)
	{
		i = k;
		while (i)
		{
			if (array[i] < array[i - 1])
				ft_end_programm("KO\n");
			i--;
		}
		k++;
	}
	ft_end_programm("OK\n");
}
