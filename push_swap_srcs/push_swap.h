#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
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
	char					*str;
	struct s_instructions	*next;
	struct s_instructions	*prev;
}	t_instr;

typedef struct s_sort
{
	t_stack	**head_stack_a;
	t_stack	**head_stack_b;
	t_instr	**head_instr;
	int		list_size;
	int		sorted_a;
	int		*segm_size;
}	t_sort;

/*#*#*#*#*#*#*#*#*#OPERATIONS/FT_PUSH.C#*#*#*#*#*#*#*#*#*/
void	ft_pa(t_stack **head_stack_a, t_stack **head_stack_b, \
		t_instr **head_instr, int write_flag);
void	ft_pb(t_stack **head_stack_a, t_stack **head_stack_b, \
		t_instr **head_instr, int write_flag);

/*#*#*#*#*#*#*#*#*#OPERATIONS/FT_ROTATE_REVERSE.C#*#*#*#*#*#*#*#*#*/
void	ft_rra(t_stack **head_stack_a, t_instr **head_instr, int write_flag);
void	ft_rrb(t_stack **head_stack_b, t_instr **head_instr, int write_flag);
void	ft_rrr(t_stack **head_stack_a, t_stack **head_stack_b, \
		t_instr **head_instr, int write_flag);

/*#*#*#*#*#*#*#*#*#OPERATIONS/FT_ROTATE.C#*#*#*#*#*#*#*#*#*/
void	ft_ra(t_stack **head_stack_a, t_instr **head_instr, int write_flag);
void	ft_rb(t_stack **head_stack_b, t_instr **head_instr, int write_flag);
void	ft_rr(t_stack **head_stack_a, t_stack **head_stack_b, \
		t_instr **head_instr, int write_flag);

/*#*#*#*#*#*#*#*#*#OPERATIONS/FT_SWAP.C#*#*#*#*#*#*#*#*#*/
void	ft_sa(t_stack **head_stack_a, t_instr **head_instr, int write_flag);
void	ft_sb(t_stack **head_stack_b, t_instr **head_instr, int write_flag);
void	ft_ss(t_stack **head_stack_a, t_stack **head_stack_b, \
		t_instr **head_instr, int write_flag);

/*#*#*#*#*#*#*#*#*#SORT_5_ELEMENTS#*#*#*#*#*#*#*#*#*/
void	ft_sort_5_elements(t_stack **head_stack_a, t_stack **head_stack_b, \
		t_instr **head_instr, int list_size);
void	ft_sort_2_elements_b(t_stack **head_stack_b, t_instr **head_instr);
void	ft_sort_3_elements_b(t_stack **head_stack_b, t_instr **head_instr);
void	case_1(t_stack **head_stack_b, t_instr **head_instr);
void	case_2(t_stack **head_stack_b, t_instr **head_instr);
void	case_3(t_stack **head_stack_b, t_instr **head_instr);
void	case_5(t_stack **head_stack_b, t_instr **head_instr);
void	case_6(t_stack **head_stack_b, t_instr **head_instr);

/*#*#*#*#*#*#*#*#*#SORT_ELEMENTS#*#*#*#*#*#*#*#*#*/
void	case_2_a(t_stack **head_stack_a, t_stack **head_stack_b, \
		int sorted_a, t_instr **head_instr);
void	case_1_a(t_stack **head_stack_a, t_stack **head_stack_b, \
		int sorted_a, t_instr **head_instr);
void	case_3_a(t_stack **head_stack_a, t_stack **head_stack_b, \
		int sorted_a, t_instr **head_instr);
void	case_4_a(t_stack **head_stack_a, t_stack **head_stack_b, \
		int sorted_a, t_instr **head_instr);
void	case_5_a(t_stack **head_stack_a, t_stack **head_stack_b, \
		int sorted_a, t_instr **head_instr);
void	case_6_a(t_stack **head_stack_a, t_stack **head_stack_b, \
		int sorted_a, t_instr **head_instr);
int		ft_sort_if_2_elements_a(t_stack **head, int sorted_a, \
		t_instr **head_instr);
int		ft_sort_if_3_elements_a(t_stack **head_stack_a, t_stack **head_stack_b, \
		int sorted_a, t_instr **head_instr);

void	case_1_b(t_stack **head_stack_a, t_stack **head_stack_b, \
		t_instr **head_instr);
void	case_2_b(t_stack **head_stack_a, t_stack **head_stack_b, \
		t_instr **head_instr);
void	case_3_b(t_stack **head_stack_a, t_stack **head_stack_b, \
		t_instr **head_instr);
void	case_4_b(t_stack **head_stack_a, t_stack **head_stack_b, \
		t_instr **head_instr);
void	case_5_b(t_stack **head_stack_a, t_stack **head_stack_b, \
		t_instr **head_instr);
int		ft_sort_if_2_elements_b(t_stack **head, int sorted_a, \
		t_instr **head_instr);
int		ft_sort_if_3_elements_b(t_stack **head_stack_a, t_stack **head_stack_b, \
		int sorted_a, t_instr **head_instr);

/*#*#*#*#*#*#*#*#*#UTILS/UTILS.C#*#*#*#*#*#*#*#*#*/
void	ft_error(char *str);
t_stack	*ft_create_new_stack(void);
t_stack	*ft_push_back_list(t_stack *prev, long long int value);
void	ft_free_stack(t_stack *head);
t_list	*ft_lstlast(t_list *lst);
void	ft_bzero(void *s, size_t n);
void	ft_create_new_instr(t_instr **head_instr, char *str);
void	ft_push_back_new_instr(t_instr **head_instr, char *str);
void	ft_print_instr(t_instr *head);

/*#*#*#*#*#*#*#*#*#FT_GET_MEDIAN.C#*#*#*#*#*#*#*#*#*/
int		ft_get_median(t_stack *head, int list_size);
int		ft_check_if_stack_is_sorted(int	*array, int list_size);
void	ft_sort_array(int *array, int left, int right, int tmp);
int		*ft_create_blank_array(int size);
int		*ft_create_array_from_list(int list_size, t_stack *head);

/*#*#*#*#*#*#*#*#*#FT_GET_STACK_DATA.C#*#*#*#*#*#*#*#*#*/
void	ft_get_stack_data(t_stack *head_stack_a, char **argv, int i);
void	ft_check_if_args_are_int(char **argv, int i);
void	ft_check_duplicates_main(t_stack *head_stack_a);
void	ft_check_duplicates(int *array, size_t size, int value_check);

/*#*#*#*#*#*#*#*#*#FT_SORT_STACK.C#*#*#*#*#*#*#*#*#*/
t_instr	*ft_sort_stack_main(t_stack **head_stack_a, \
		t_stack *head_stack_b, int list_size, int flag);
int		ft_sort_stack_a(t_sort *s, t_stack **head_stack_b, int list_size, \
		int sorted_a);
void	ft_sort_5_elements(t_stack **head_stack_a, t_stack **head_stack_b, \
		t_instr **head_instr, int list_size);

#endif