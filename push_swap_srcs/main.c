#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*head_stack_a;
	int		i;
	int		debug_flag;

	i = 1;
	debug_flag = 0;
	if (argc == 1)
		exit(0);
	if (!ft_strcmp(argv[1], "-v"))
	{
		debug_flag = ++i;
		printf("%d\n", debug_flag);
		if (argc == 2)
			exit(0);
		else if (argc == 3)
		{
			i = 0;
			argv = ft_split(argv[2], ' ');
			if (argv[0] == NULL)
				exit(0);
		}
	}
	else if (argc == 2)
	{
		i = 0;
		argv = ft_split(argv[1], ' ');
		if (argv[0] == NULL)
			exit(0);
	}
	head_stack_a = ft_create_new_stack();
	ft_get_stack_data(head_stack_a, argv, i);
	ft_sort_stack_main(&head_stack_a, NULL, \
		ft_lstsize((t_list *)head_stack_a), debug_flag);
	
	printf("SA "); ft_print(head_stack_a);
	int *array;
	array = ft_create_array_from_list(ft_lstsize((t_list *)head_stack_a), head_stack_a);
	if (ft_check_if_stack_is_sorted(array, ft_lstsize((t_list *)head_stack_a)))
		printf("SORTTED\n");
	else
		printf("NOT\n");
	return (0);
}
