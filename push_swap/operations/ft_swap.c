#include "../push_swap.h"

void    ft_sa(t_stack **head_stack_a)
{
    t_stack *tmp1;

    write(1, "sa\n", 3);
    if ((*head_stack_a == NULL) || ((*head_stack_a) && !(*head_stack_a)->next))
        return ;
    tmp1 = (*head_stack_a);
    (*head_stack_a) = (*head_stack_a)->next;
    tmp1->next = (*head_stack_a)->next;
    (*head_stack_a)->next = tmp1;
}

void    ft_sb(t_stack **head_stack_b)
{
    t_stack *tmp1;

    write(1, "sb\n", 3);
    if ((*head_stack_b == NULL) || ((*head_stack_b) && !(*head_stack_b)->next))
        return ;
    tmp1 = (*head_stack_b);
    (*head_stack_b) = (*head_stack_b)->next;
    tmp1->next = (*head_stack_b)->next;
    (*head_stack_b)->next = tmp1;
}
void    ft_ss(t_stack **head_stack_a, t_stack **head_stack_b)
{
    write(1, "ss\n", 3);
    ft_sa(head_stack_a);
    ft_sb(head_stack_b);
}