#include "checker.h"

static	void	part_2(t_instr *tmp_instr, \
				t_stack **head_stack_a, t_stack **head_stack_b)
{
	if (!ft_strcmp(tmp_instr->str, "pa\n"))
		ft_pa(head_stack_a, head_stack_b);
	else if (!ft_strcmp(tmp_instr->str, "pb\n"))
		ft_pb(head_stack_a, head_stack_b);
	else if (!ft_strcmp(tmp_instr->str, "ra\n"))
		ft_ra(head_stack_a);
	else if (!ft_strcmp(tmp_instr->str, "rb\n"))
		ft_rb(head_stack_b);
	else if (!ft_strcmp(tmp_instr->str, "rr\n"))
		ft_rr(head_stack_a, head_stack_b);
	else if (!ft_strcmp(tmp_instr->str, "rra\n"))
		ft_rra(head_stack_a);
	else if (!ft_strcmp(tmp_instr->str, "rrb\n"))
		ft_rrb(head_stack_b);
	else if (!ft_strcmp(tmp_instr->str, "rrr\n"))
		ft_rrr(head_stack_a, head_stack_b);
}

void	ft_exec_instructions(t_instr *head_instr, t_stack **head_stack_a, \
											int debug_flag)
{
	t_instr	*tmp_instr;
	t_stack	*head_stack_b;

	tmp_instr = head_instr;
	head_stack_b = NULL;
	while (tmp_instr && tmp_instr->str[0])
	{
		if (!ft_strcmp(tmp_instr->str, "sa\n"))
			ft_sa(head_stack_a);
		else if (!ft_strcmp(tmp_instr->str, "sb\n"))
			ft_sb(&head_stack_b);
		else if (!ft_strcmp(tmp_instr->str, "ss\n"))
			ft_ss(head_stack_a, &head_stack_b);
		else
			part_2(tmp_instr, head_stack_a, &head_stack_b);
		if (debug_flag)
			ft_print_stacks(*head_stack_a, head_stack_b, tmp_instr);
		tmp_instr = tmp_instr->next;
	}
	ft_free_instr(head_instr);
	if (head_stack_b)
		ft_end_programm("KO\n");
}

static	int	helper(int number, int len, int flag)
{
	if (flag)
	{
		len = 14 - len;
		while (len-- > 0)
			printf(" ");
		return (len);
	}
	if (number < 0)
		len++;
	while (number != 0)
	{
		number = number / 10;
		len++;
	}
	return (len);
}

static	void	ft_print_stacks_part_2(t_stack *a, t_stack *b, \
							int a_flag, int b_flag)
{
	int	len;

	while (a_flag || b_flag)
	{
		if (a_flag)
		{
			printf("%d", a->value);
			len = helper(a->value, 0, 0);
			helper(a->value, len, 1);
		}
		else
			helper(0, 0, 1);
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
}

void	ft_print_stacks(t_stack *a, t_stack *b, t_instr *current_instr)
{
	int			a_flag;
	int			b_flag;

	a_flag = 0;
	b_flag = 0;
	if (a)
		a_flag = 1;
	if (b)
		b_flag = 1;
	system ("clear");
	printf("-------------------------\n");
	printf("  STACK_A   |   STACK_B  \n");
	printf("-------------------------\n");
	printf("instruction - %s\n", current_instr->str);
	ft_print_stacks_part_2(a, b, a_flag, b_flag);
	printf("-------------------------\n\n");
	usleep(SLEEP);
}
