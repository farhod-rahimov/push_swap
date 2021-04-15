#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*head_stack_a;
	int		i;

	i = 1;
	if (argc == 1)
		exit(0);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		i = 0;
		if (argv[0] == NULL)
			exit(0);
	}
	head_stack_a = ft_create_new_stack();
	ft_get_stack_data(head_stack_a, argv, i);
	ft_sort_stack_main(&head_stack_a, NULL, \
		ft_lstsize((t_list *)head_stack_a), 0);
	return (0);
}
