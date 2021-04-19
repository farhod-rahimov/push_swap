#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include <stdio.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define ERROR "Error\n"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

typedef struct s_instructions
{
	char					str[5];
	struct s_instructions	*next;
}	t_instr;

/******************FT_GET_STACK_DATA.C******************/
void	ft_get_stack_data(t_stack *head_stack_a, char **arv, int i);
void	ft_check_if_args_are_int(char **argv, int i);
void	ft_check_duplicates_main(t_stack *head_stack_a);

/******************FT_GET_INSTRUCTIONS.C******************/
void	ft_get_instructions(t_instr *instructions_head);
void	ft_check_if_instr_are_correct(t_instr *instructions_head);
char	**ft_get_possible_instr(void);
void	ft_printos(t_instr *head); //delete

/******************FT_EXEC_INSTRUCTIONS.C******************/
void	ft_exec_instructions(t_instr *head_instr, t_stack **head_stack_a);

/******************FT_SWAP.C******************/
void	ft_sa(t_stack **head_stack_a);
void	ft_sb(t_stack **head_stack_b);
void	ft_ss(t_stack **head_stack_a, t_stack **head_stack_b);

/******************FT_PUSH.C******************/
void	ft_pa(t_stack **head_stack_a, t_stack **head_stack_b);
void	ft_pb(t_stack **head_stack_a, t_stack **head_stack_b);

/******************FT_ROTATE.C******************/
void	ft_ra(t_stack **head_stack_a);
void	ft_rb(t_stack **head_stack_b);
void	ft_rr(t_stack **head_stack_a, t_stack **head_stack_b);

/******************FT_ROTATE_REVERSE.C******************/
void	ft_rra(t_stack **head_stack_a);
void	ft_rrb(t_stack **head_stack_b);
void	ft_rrr(t_stack **head_stack_a, t_stack **head_stack_b);

/******************FT_CHECK_IF_STACK_IS_SORTED.C******************/
void	ft_check_if_stack_is_sorted(t_stack *head);

/******************UTILS_PART_1.C******************/
void	ft_error(char *str);
void	ft_end_programm(char *str);
void	ft_free_two_dimensional_array(char **array);
void	ft_free_instr(t_instr *head);

/******************UTILS_PART_2.C******************/
t_stack	*ft_create_new_stack(void);
t_instr	*ft_create_new_instr(void);
t_stack	*ft_push_back_list(t_stack *prev, long long int value);

/******************FT_STRCMP.C******************/
int		ft_strcmp(char *s1, char *s2);

#endif