#include "../checker.h"

void    ft_ra(t_stack **head_stack_a)
{
    t_stack *tmp;
    t_stack *last;

    if ((*head_stack_a) == NULL || ((*head_stack_a) && !(*head_stack_a)->next))
        return ;
    tmp = (*head_stack_a);
    (*head_stack_a) = (*head_stack_a)->next;
    last = (t_stack *)ft_lstlast((t_list *)(*head_stack_a));
    last->next = tmp;
    tmp->next = NULL;
}
void    ft_rb(t_stack **head_stack_b)
{
    t_stack *tmp;
    t_stack *last;

    if ((*head_stack_b) == NULL || ((*head_stack_b) && !(*head_stack_b)->next))
        return ;
    tmp = (*head_stack_b);
    (*head_stack_b) = (*head_stack_b)->next;
    last = (t_stack *)ft_lstlast((t_list *)(*head_stack_b));
    last->next = tmp;
    tmp->next = NULL;
}
void    ft_rr(t_stack **head_stack_a, t_stack **head_stack_b)
{
    ft_ra(head_stack_a);
    ft_rb(head_stack_b);
}
