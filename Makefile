all:		
				@ cd ./checker_srcs && make && cp ./checker ../ && cd ../
				@ cd ./push_swap_srcs && make && cp ./push_swap ../ && cd ../

test:			all
				@ cd ./my_tests && make && cp ./test ../ && cp ./test_wc ../ && cp ./test_arg ../ && cd ../

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
				@ rm ./test
				@ rm ./test_wc
				@ rm ./test_arg

re:				fclean all

.PHONY:			all clean fclean re test