all:		
				@ cd ./checker_srcs && make && cp ./checker ../ && cd ../
				@ cd ./push_swap_srcs && make && cp ./push_swap ../ && cd ../

test:			all
				@ cd ./my_tests && make
				@ echo
				@ echo "GO to ./my_tests AND RUN ANY TESTS (./test or ./test_wc or ./test_arg)"
				@ echo "in ./my_tests/Makefile you can change NUM_TEST and NUM_ARGS"
				@ echo "by default NUM_TEST = 100 and NUM_ARGS = 100"

clean:
				@ cd ./checker_srcs && make clean && cd ../
				@ cd ./push_swap_srcs && make clean && cd ../
				@ cd ./my_tests && make clean && cd ../

fclean:			
				@ cd ./checker_srcs && make fclean && cd ../
				@ cd ./push_swap_srcs && make fclean && cd ../
				@ cd ./my_tests && make fclean && cd ../
				@ rm ./checker
				@ rm ./push_swap

re:				fclean all

.PHONY:			all clean fclean re test