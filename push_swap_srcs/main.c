#include "push_swap.h"

static	int	get_argv(char ***argv, int i)
{
	*argv = ft_split((*argv)[i], ' ');
	if ((*argv)[0] == NULL)
		exit(0);
	return (0);
}

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
		if (argc == 2)
			exit(0);
		else if (argc == 3)
			i = get_argv(&argv, 2);
	}
	else if (argc == 2)
		i = get_argv(&argv, 1);
	head_stack_a = ft_create_new_stack();
	ft_get_stack_data(head_stack_a, argv, i);
	ft_sort_stack_main(&head_stack_a, NULL, \
		ft_lstsize((t_list *)head_stack_a), 0);
	return (0);
}
