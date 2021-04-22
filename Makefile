all:		
				@ cd ./checker_srcs && make && cp ./checker ../ && cd ../
				@ cd ./push_swap_srcs && make && cp ./push_swap ../ && cd ../
				@ cp ./test/test.sh ./
				@ echo "for testing 'push_swap' run 'make test'"

test:
				@ ./test.sh 1 100 40

clean:
				@ cd ./checker_srcs && make clean && cd ../
				@ cd ./push_swap_srcs && make clean && cd ../

fclean:			
				@ cd ./checker_srcs && make fclean && cd ../
				@ cd ./push_swap_srcs && make fclean && cd ../
				@ rm ./checker
				@ rm ./push_swap
				@ rm test.sh

re:				fclean all

.PHONY:			all clean fclean re test