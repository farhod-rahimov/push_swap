#include "../checker.h"

void	ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}

void	ft_end_programm(char *str)
{
	write(1, str, ft_strlen(str));
	exit(0);
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

t_instr	*ft_create_new_instr(void)
{
	t_instr	*new_instr;

	new_instr = (t_instr *)malloc(sizeof(t_instr));
	if (new_instr == NULL)
		ft_error(ERROR);
	new_instr->next = NULL;
	return (new_instr);
}

t_stack	*ft_push_back_list(t_stack *prev, long long int value)
{
	t_stack	*new_element;

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

void	ft_free_two_dimensional_array(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

void	ft_free_instr(t_instr *head)
{
	t_instr	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
