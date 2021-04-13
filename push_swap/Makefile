SRCS =			./main.c \
				./ft_get_stack_data.c \
				./utils/ft_atoi.c \
				./utils/utils.c \
				./utils/ft_strlen.c \
				./utils/ft_lstsize.c \
				./utils/ft_isdigit.c \
				./utils/ft_lstlast.c \
				./utils/ft_bzero.c \
				./ft_get_median.c \
				./ft_sort_stack.c \
				./operations/ft_push.c \
				./operations/ft_rotate_reverse.c \
				./operations/ft_rotate.c \
				./operations/ft_swap.c

OBJS =			$(SRCS:.c=.o)

GCC = 			gcc

FLAGS =			-Wall -Wextra -Werror

NAME =			push_swap

%.o:			%.c
				@ $(GCC) -c $(FLAGS) $< -o $(<:.c=.o)

all: 			$(NAME)

$(NAME):		$(OBJS)
				@ $(GCC) -o $(NAME) $(OBJS)
				@ echo 'push_swap built, run ./push_swap'

clean:
				@ rm -f $(OBJS)

fclean:			clean
				@ rm -f $(NAME)

re:				fclean all

.PHONY:			all clean fclean re