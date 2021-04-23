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
	t_instr	*head;
	int		i;
	int		debug_flag;

	i = 1;
	debug_flag = 0;
	if (argc == 1)
		exit(0);
	if (argc == 2)
		i = get_argv(&argv, 1);
	head_stack_a = ft_create_new_stack();
	ft_get_stack_data(head_stack_a, argv, i);
	head = ft_sort_stack_main(&head_stack_a, NULL, \
		ft_lstsize((t_list *)head_stack_a), 0);
	ft_print_instr(head);
	return (0);
}
