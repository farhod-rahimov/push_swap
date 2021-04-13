# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# include <stdio.h> //delete

# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define ERROR "Error\n"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
} t_stack;


/******************FT_GET_STACK_DATA.C******************/
void    ft_get_stack_data(t_stack *head_stack_a, char **arv);
void	ft_check_if_args_are_int(char **argv);
void	ft_check_duplicates_main(t_stack *head_stack_a);

/******************ft_GET_MEDIAN.C******************/
int    ft_get_median(t_stack *head, int list_size);
int		ft_check_if_stack_is_sorted(int	*array, int list_size);
void	ft_sort_array(int *array, int left, int right, int tmp);
int		ft_sort_if_3_elements(t_stack **head, int sorted_a);
int		ft_sort_if_2_elements(t_stack **head, int sorted_a);
// void	ft_sort_if_3_elements(t_stack **head, int list_size, int flag);
// void	ft_sort_if_2_elements(t_stack **head, int list_size, int flag);
int		*ft_create_blank_array(int size);
int    *ft_create_array_from_list(int list_size, t_stack *head);
void    ft_print_array(int *array, int size); // delete

/******************FT_SORT_STACK.C******************/
void	ft_sort_stack_main(t_stack **head_stack_a, t_stack *head_stack_b, int list_size, int flag);

/******************FT_SWAP.C******************/
void    ft_sa(t_stack **head_stack_a);
void    ft_sb(t_stack **head_stack_b);
void    ft_ss(t_stack **head_stack_a, t_stack **head_stack_b);

/******************FT_PUSH.C******************/
void    ft_pa(t_stack **head_stack_a, t_stack **head_stack_b);
void    ft_pb(t_stack **head_stack_a, t_stack **head_stack_b);

/******************FT_ROTATE.C******************/
void    ft_ra(t_stack **head_stack_a);
void    ft_rb(t_stack **head_stack_b);
void    ft_rr(t_stack **head_stack_a, t_stack **head_stack_b);

/******************FT_ROTATE_REVERSE.C******************/
void    ft_rra(t_stack **head_stack_a);
void    ft_rrb(t_stack **head_stack_b);
void    ft_rrr(t_stack **head_stack_a, t_stack **head_stack_b);

/******************UTILS.C******************/
void	ft_error(char *str);
t_stack	*ft_create_new_stack(void);
t_stack *ft_push_back_list(t_stack *prev, long long int value);
void    ft_print(t_stack *head); // delete
// void	ft_free_two_dimensional_array(char **array);
void	ft_free_stack(t_stack *head);
t_list	*ft_lstlast(t_list *lst);
void	ft_bzero(void *s, size_t n);


void	ft_trash(t_stack **head_stack_a, t_stack *head_stack_b, int *segment_size); // delete
//89 131 51 496 335 174 213 453 266 337 277 421 403 276 71 155 99 27 346 464
//93 97 66 16 3 74 60 51 69 40 73 65 64 79 78
//7032 1787 3767 2939 1815 9440 6296 7191 7396 1190 1000 3601 1390 2571 9002
// 3744 685 6905 5988 5810 8381 6527 3943 913 7149 7503 1947 6506 9081 4888 4193 4242 9421 3584 9812 3041 6953 6522 1235 8334 3345 192 5243 8528 1074 3496 2271 1758 400 8258 7568 8780 4785 1510 9693 1934 9012 1639 8439 8093 6526 2631 2335 5947 6215 2146 8988 3167 8667 222 1501 2011 413 6743 539 1487 238 2809 3245 637 1067 812 9417 5852 2321 9109 7785 1332 747 6223 9425 7273 8854 1759 3220 5068 3904 2207 8235 2570 2428 9735 4581 2841 6478 5119 4327 6715 7928 7571 7352 8994 8382 6768 4845
// 192 400 685 913 1074 1235 1758 1947 2271 3041 3345 3496 3584 3744 3943 4193 4242 4785 4888 5243 5810 5988 6506 6522 6527 6905 6953 7149 7503 7568 8258 8334 8381 8528 8780 9081 9421 9812

//./test.sh 1 100 10
// /usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/Library/Apple/usr/bin:/Users/farhod