all:		
				cd ./checker_srcs && make && cp ./checker ../ && cd ../
				cd ./push_swap_srcs && make && cp ./push_swap ../ && cd ../
				echo 'checker and push_swap are built'

clean:
				cd ./checker_srcs && make clean && cd ../
				cd ./push_swap_srcs && make clean && cd ../

fclean:			
				cd ./checker_srcs && make fclean && cd ../
				cd ./push_swap_srcs && make fclean && cd ../
				rm ./checker
				rm ./push_swap

re:				fclean all

.PHONY:			all clean fclean re