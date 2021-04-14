#include "checker.h"

int main(int argc, char **argv)
{
    t_stack *head_stack_a;
    t_instr *head_instructions;
    int     i;

    i = 1;
    if (argc == 1)
        exit(0);
    else if (argc == 2)
    {
        argv = ft_split(argv[1], ' ');
        i = 0;
    }
    head_stack_a = ft_create_new_stack();
    head_instructions = ft_create_new_instr();
    ft_get_stack_data(head_stack_a, argv, i);
    ft_get_instructions(head_instructions);
    ft_exec_instructions(head_instructions, &head_stack_a);
    ft_check_if_stack_is_sorted(head_stack_a);
    // ft_free_stack(head_stack_a);
    return (0);
}