#include "../push_swap.h"

void	case_1_b(t_stack **head_stack_a, t_stack **head_stack_b, t_instr **head_instr)
{
	(void)head_stack_a;
	ft_rrb(head_stack_b, head_instr);
	ft_sb(head_stack_b, head_instr);
}

void	case_2_b(t_stack **head_stack_a, t_stack **head_stack_b, t_instr **head_instr)
{
	(void)head_stack_a;
	ft_sb(head_stack_b, head_instr);
}

void	case_3_b(t_stack **head_stack_a, t_stack **head_stack_b, t_instr **head_instr)
{
	(void)head_stack_a;
	ft_rrb(head_stack_b, head_instr);
}
