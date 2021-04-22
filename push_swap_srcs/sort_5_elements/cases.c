#include "../push_swap.h"

void	case_1(t_stack **head_stack_b, t_instr **head_instr)
{
	ft_rb(head_stack_b, head_instr, 1);
}

void	case_2(t_stack **head_stack_b, t_instr **head_instr)
{
	ft_rrb(head_stack_b, head_instr, 1);
}

void	case_3(t_stack **head_stack_b, t_instr **head_instr)
{
	ft_sb(head_stack_b, head_instr, 1);
}

void	case_5(t_stack **head_stack_b, t_instr **head_instr)
{
	ft_rrb(head_stack_b, head_instr, 1);
	ft_sb(head_stack_b, head_instr, 1);
}

void	case_6(t_stack **head_stack_b, t_instr **head_instr)
{
	ft_rb(head_stack_b, head_instr, 1);
	ft_sb(head_stack_b, head_instr, 1);
}
