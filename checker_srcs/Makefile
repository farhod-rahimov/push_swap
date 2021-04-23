SRCS =			./main.c \
				./ft_get_stack_data.c \
				./utils/ft_strcmp.c \
				./utils/utils_part_1.c \
				./utils/utils_part_2.c \
				./utils/ft_atoi.c \
				./utils/ft_bzero.c \
				./utils/ft_isdigit.c \
				./utils/ft_lstlast.c \
				./utils/ft_lstsize.c \
				./utils/ft_strdup.c \
				./utils/ft_strlen.c \
				./utils/ft_split.c \
				./ft_get_instructions.c \
				./ft_exec_instructions.c \
				./ft_check_if_stack_is_sorted.c \
				./operations/ft_push.c \
				./operations/ft_rotate_reverse.c \
				./operations/ft_rotate.c \
				./operations/ft_swap.c 

OBJS =			$(SRCS:.c=.o)

GCC = 			gcc

FLAGS =			-Wall -Wextra -Werror

NAME =			checker

%.o:			%.c
				@ $(GCC) -c $(FLAGS) $< -o $(<:.c=.o)

all: 			$(NAME)

$(NAME):		$(OBJS)
				@ $(GCC) -o $(NAME) $(OBJS)
				@ echo 'checker built, run ./checker'

clean:
				@ rm -f $(OBJS)

fclean:			clean
				@ rm -f $(NAME)

re:				fclean all

.PHONY:			all clean fclean re