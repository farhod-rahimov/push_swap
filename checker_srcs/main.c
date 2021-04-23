#include "checker.h"

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
	t_instr	*head_instructions;
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
	head_instructions = ft_create_new_instr();
	ft_get_stack_data(head_stack_a, argv, i);
	ft_get_instructions(head_instructions);
	ft_exec_instructions(head_instructions, &head_stack_a, debug_flag);
	ft_check_if_stack_is_sorted(head_stack_a);
}
