#include "push_swap.h"

int	ft_get_median(t_stack *head, int list_size)
{
	int				*array;
	long long int	median;

	if (list_size == 1)
		return (head->value);
	array = ft_create_array_from_list(list_size, head);
	if (!ft_check_if_stack_is_sorted(array, list_size))
		ft_sort_array(array, 0, list_size - 1, 0);
	if (list_size % 2 == 0)
	{
		median = array[(list_size / 2)];
		median = (median + array[(list_size / 2) - 1]) / 2;
	}
	else
		median = array[list_size / 2];
	free(array);
	return ((int)median);
}

int	ft_check_if_stack_is_sorted(int	*array, int list_size)
{
	int	k;
	int	i;

	k = 1;
	while (k < list_size)
	{
		i = k;
		while (i)
		{
			if (array[i] < array[i - 1])
				return (0);
			i--;
		}
		k++;
	}
	return (1);
}

void	ft_sort_array(int *array, int left, int right, int tmp)
{
	int	pivot;
	int	initial_left;
	int	initial_right;

	if (left < right)
	{
		pivot = array[left];
		initial_left = left;
		initial_right = right;
		while (left < right)
		{
			while (array[left] < pivot)
				left++;
			while (array[right] > pivot)
				right--;
			if (left <= right)
			{
				tmp = array[left];
				array[left++] = array[right];
				array[right--] = tmp;
			}
		}
		ft_sort_array(array, initial_left, right, 0);
		ft_sort_array(array, left, initial_right, 0);
	}
}

int	*ft_create_blank_array(int size)
{
	int	*array;

	array = (int *)malloc(sizeof(int) * size);
	if (array == NULL)
		ft_error(ERROR);
	return (array);
}

int	*ft_create_array_from_list(int list_size, t_stack *tmp)
{
	int	i;
	int	*array;

	array = (int *)malloc(sizeof(int) * list_size);
	if (array == NULL)
		ft_error(ERROR);
	i = 0;
	while (i < list_size && tmp)
	{
		array[i++] = tmp->value;
		tmp = tmp->next;
	}
	return (array);
}
