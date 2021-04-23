#include "test.h"

void    remove_duplicates(int **array, int i);
char	*ft_itoa(int n);
void    execute_Push_swap_and_Checker(char **random);

int main(void)
{
    char **random;
    int *array;
    int size;
    int i;

    size = 5;
    i = 0;
    array = (int *)malloc(sizeof(int) * size);
    random = (char **)malloc(sizeof(char *) * (size + 1));
    random[size] = NULL;
    while (i < size)
    {
        array[i] = rand();
        i++;
    }
    remove_duplicates(&array, i);
    i = 0;
    while (i < size)
    {
        random[i] = ft_itoa(array[i]);
        i++;
    }
    execute_Push_swap_and_Checker(random);
    // i = 0;
    // while (i < size)
    // {
    //     printf("%s ", random[i++]);
    // }
    // printf("\n");
    return (0);
}

void    execute_Push_swap_and_Checker(char **random)
{
    int initial_fd[2];
    int pipe_fd[2];
    int i;
    int status;
    pid_t pid;

    i = 0;
    initial_fd[0] = dup(0);
    initial_fd[1] = dup(1);
    pipe(pipe_fd);
    dup2(pipe_fd[1], 1);
    dup2(pipe_fd[0], 0);
    pid = fork();
    if (pid == 0)
    {
        close(pipe_fd[0]);
        if (execve("../push_swap", random, NULL) == -1)
            write(2, "error\n", 6);
    }
    else
    {
        waitpid(pid, &status, 0);
        close(pipe_fd[1]);
        dup2(initial_fd[1], 1);
        if (execve("../checker", random, NULL) == -1)
            write(2, "error\n", 6);
    }
}


void    remove_duplicates(int **array, int i)
{
    int flag;
    int k;
    int l;
    int tmp;
    int duplicates;

    k = 0;
    while (k < i)
    {
        tmp = (*array)[k];
        flag = 0;
        l = 0;
        duplicates = 0;
        while (l < i)
        {
            if (tmp == (*array)[l])
                duplicates++;
            if (duplicates > 1)
            {
                (*array)[l] = rand();
                k = 0;
                flag = 1;
                break ;
            }
            l++;
        }
        if (!flag)
            k++;
    }
}