#include "../push_swap.h"

void	case_4_b(t_stack **head_stack_a, t_stack **head_stack_b, t_instr **head_instr)
{
	(void)head_stack_a;
	ft_rb(head_stack_b, head_instr);
	ft_sb(head_stack_b, head_instr);
}

void	case_5_b(t_stack **head_stack_a, t_stack **head_stack_b, t_instr **head_instr)
{
	(void)head_stack_a;
	ft_ra(head_stack_b, head_instr);
}
