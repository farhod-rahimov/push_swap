#include "../push_swap.h"

void	ft_print_stacks(t_stack *a, t_stack *b, char *current_instr)
{
    (void)current_instr;
	int a_flag;
	int	b_flag;

	a_flag = 0;
	b_flag = 0;
	if (a)
		a_flag = 1;
	if (b)
		b_flag = 1;
	printf("-----------------------\n");
	printf("STACK_A		STACK_B\n");
	printf("-----------------------\n");
	// printf("instruction - %s\n", current_instr);
	while (a_flag || b_flag)
	{
		if (a_flag)
			printf("%d		", a->value);
		else
			printf("		");
		if (b_flag)
			printf("%d\n", b->value);
		else
			printf("\n");
		if (a_flag)
			a = a->next;
		if (b_flag)
			b = b->next;
		if (a == NULL)
			a_flag = 0;
		if (b == NULL)
			b_flag = 0;
	}
	printf("-----------------------\n\n");
}