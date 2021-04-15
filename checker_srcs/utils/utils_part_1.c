#include "../checker.h"

void	ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}

void	ft_end_programm(char *str)
{
	write(1, str, ft_strlen(str));
	exit(0);
}

void	ft_free_two_dimensional_array(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

void	ft_free_instr(t_instr *head)
{
	t_instr	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
