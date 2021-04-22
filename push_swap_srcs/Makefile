SRCS =			./main.c \
				./ft_get_stack_data.c \
				./utils/ft_atoi.c \
				./utils/utils.c \
				./utils/ft_strlen.c \
				./utils/ft_strcmp.c \
				./utils/ft_lstsize.c \
				./utils/ft_isdigit.c \
				./utils/ft_lstlast.c \
				./utils/ft_bzero.c \
				./utils/ft_split.c \
				./ft_get_median.c \
				./ft_sort_stack.c \
				./sort_5_elements/cases.c \
				./sort_5_elements/ft_sort_5_elements.c \
				./sort_elements/cases_part_1_a.c \
				./sort_elements/cases_part_2_a.c \
				./sort_elements/ft_sort_if_2_elements_a.c \
				./sort_elements/ft_sort_if_3_elements_a.c \
				./sort_elements/cases_part_1_b.c \
				./sort_elements/cases_part_2_b.c \
				./sort_elements/ft_sort_if_2_elements_b.c \
				./sort_elements/ft_sort_if_3_elements_b.c \
				./operations/ft_push.c \
				./operations/ft_rotate_reverse.c \
				./operations/ft_rotate.c \
				./operations/ft_swap.c

OBJS =			$(SRCS:.c=.o)

GCC = 			gcc

FLAGS =			-Wall -Wextra -Werror

NAME =			push_swap

%.o:			%.c
				$(GCC) -c $(FLAGS) $< -o $(<:.c=.o)

all: 			$(NAME)

$(NAME):		$(OBJS)
				$(GCC) -o $(NAME) $(OBJS)
				echo 'push_swap built, run ./push_swap'

clean:
				rm -f $(OBJS)

fclean:			clean
				rm -f $(NAME)

re:				fclean all

.PHONY:			all clean fclean re