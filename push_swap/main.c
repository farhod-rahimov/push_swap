#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *head_stack_a;

    if (argc == 1)
        exit(0);
    head_stack_a = ft_create_new_stack();
    ft_get_stack_data(head_stack_a, argv);
    // ft_get_median(head_stack_a);
    ft_sort_stack_main(&head_stack_a, NULL, ft_lstsize((t_list *)head_stack_a), 0);
    // while (1)
    //     ;
    // ft_print(head_stack_a);
    ft_free_stack(head_stack_a);
    return (0);
}