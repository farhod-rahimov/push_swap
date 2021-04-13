#include "push_swap.h"

void    ft_print_array(int *array, int size)
{
    int i;

    i = 0;
    while (i < size)
        printf("%d ", array[i++]);
    printf("\n");
}

void	ft_print(t_stack *head)
{
	while (head)
	{
		printf("%d ", head->value);
		head = head->next;
	}
	printf("\n");
}