all:		
				@ cd ./checker_srcs && make && cp ./checker ../ && cd ../
				@ cd ./push_swap_srcs && make && cp ./push_swap ../ && cd ../

clean:
				@ cd ./checker_srcs && make clean && cd ../
				@ cd ./push_swap_srcs && make clean && cd ../
				@ echo 'make clean done'

fclean:			
				@ cd ./checker_srcs && make fclean && cd ../
				@ cd ./push_swap_srcs && make fclean && cd ../
				@ rm ./checker
				@ rm ./push_swap
				@ echo 'make fclean done'

re:				fclean all

.PHONY:			all clean fclean re