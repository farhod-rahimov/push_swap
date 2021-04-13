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