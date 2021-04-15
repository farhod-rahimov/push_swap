#include "checker.h"

void	ft_free_stack(t_stack *head)
{
	t_stack	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

void    ft_print(t_stack *head)
{
	while (head)
	{
		printf("%d ", head->value);
		head = head->next;
	}
}

void	ft_print_array(int *array, int list_size) //delete
{
	int	i;

	i = 0;
	while (i < list_size)
		printf("%d ", array[i++]);
	printf("\n");
}