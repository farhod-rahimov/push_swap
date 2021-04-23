#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <sys/wait.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef NUM_TEST
# define NUM_TEST 50
#endif

#ifndef NUM_ARG
# define NUM_ARG 5
#endif

void    remove_duplicates(int **array, int i);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s1);
void    execute_Push_swap_and_Checker(char **random);
void    execute_wc(char **random);