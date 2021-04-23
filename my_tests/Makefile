NUM_TESTS  =    100
NUM_ARGS   =    100

NAME_1 =		test
NAME_2 =		test_wc
NAME_3 =		test_arg

all: 			$(NAME_1) $(NAME_2) $(NAME_3)
				@ make clean

$(NAME_1):		
				@ clang++ -c -D NUM_TEST=$(NUM_TESTS) -D NUM_ARG=$(NUM_ARGS) ./ft_itoa.cpp ./ft_strdup.cpp ./test.cpp
				@ clang++ -o $(NAME_1) ./ft_itoa.o ./ft_strdup.o ./test.o
				@ echo 'test is built. It show only OK or KO, run ./test'

$(NAME_2):		
				@ clang++ -c -D NUM_TEST=$(NUM_TESTS) -D NUM_ARG=$(NUM_ARGS) ./ft_itoa.cpp ./ft_strdup.cpp ./test_wc.cpp
				@ clang++ -o $(NAME_2) ./ft_itoa.o ./ft_strdup.o ./test_wc.o
				@ echo 'test_wc is built. It shows only OK or KO, run ./test_wc'

$(NAME_3):		
				@ clang++ -c -D NUM_TEST=$(NUM_TESTS) -D NUM_ARG=$(NUM_ARGS) ./ft_itoa.cpp ./ft_strdup.cpp ./test_arg.cpp
				@ clang++ -o $(NAME_3) ./ft_itoa.o ./ft_strdup.o ./test_arg.o
				@ echo 'test_arg is built. It shows initial array, OK or KO and the total number of operations, run ./test_arg'

clean:
				@ rm -f *.o

fclean:			clean
				@ rm -f $(NAME_1) $(NAME_2) $(NAME_3)

re:				fclean all

.PHONY:			all clean fclean re