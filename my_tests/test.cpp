#include "test.hpp"

int initial_fd[2];

int main(void)
{
    initial_fd[0] = dup(0);
    initial_fd[1] = dup(1);
    char **random;
    int *array;
    int i;

    random = (char **)malloc(sizeof(char *) * (NUM_ARG + 1));
    random[NUM_ARG] = NULL;
    array = (int *)malloc(sizeof(int) * NUM_ARG);
    int m = 0;
    while (1)
    {
        i = 0;
        while (i < NUM_ARG)
        {
            array[i] = rand();
            i++;
        }
        remove_duplicates(&array, i);
        i = 0;
        while (i < NUM_ARG)
        {
            random[i] = ft_itoa(array[i]);
            i++;
        }
        execute_Push_swap_and_Checker(random);
        i = 0;
        while (i < NUM_ARG)
            free(random[i++]);
        if (m++ > NUM_TEST)
            exit(0);
    }
    free(array);
    free(random);
    return (0);
}

void    execute_Push_swap_and_Checker(char **random)
{
    int pipe_fd[2];
    int i;
    int status;
    pid_t pid;

    i = 0;
    pipe(pipe_fd);
    dup2(pipe_fd[1], 1);
    dup2(pipe_fd[0], 0);
    pid = fork();
    if (pid == 0)
    {
        close(pipe_fd[0]);
        if (execve("../push_swap", random, NULL) == -1)
        {
            write(2, "ERROR. Cannot launch push_swap\n", 31);
            exit(1);
        }
    }
    else
    {
        waitpid(pid, &status, 0);
        dup2(initial_fd[1], 1);
        close(pipe_fd[1]);
        pid = fork();
        if (pid == 0)
        {
            if (execve("../checker", random, NULL) == -1)
            {
                write(2, "ERROR. Cannot launch checker\n", 29);
                exit(1);
            }
        }
        else
        {
            waitpid(pid, &status, 0);
            close(pipe_fd[0]);
            close(pipe_fd[1]);
            dup2(initial_fd[1], 1);
            dup2(initial_fd[0], 0);
        }
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