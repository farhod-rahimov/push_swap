#include "../push_swap.h"

void    ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}

t_stack	*ft_create_new_stack(void)
{
	t_stack	*new_stack;

	new_stack = (t_stack *)malloc(sizeof(t_stack));
	if (new_stack == NULL)
		ft_error(ERROR);
	new_stack->next = NULL;
	return (new_stack);
}


t_stack *ft_push_back_list(t_stack *prev, long long int value)
{
	t_stack *new_element;

	if (value > MAX_INT || value < MIN_INT)
		ft_error(ERROR);
	new_element = (t_stack *)malloc(sizeof(t_stack));
	if (new_element == NULL)
		ft_error(ERROR);
	prev->next = new_element;
	new_element->value = value;
	new_element->next = NULL;
	return (new_element);
}

void    ft_print(t_stack *head)
{
	while (head)
	{
		printf("%d ", head->value);
		head = head->next;
	}
	printf("\n");
}

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
