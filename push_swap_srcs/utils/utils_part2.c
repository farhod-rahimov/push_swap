#include "../push_swap.h"

void	ft_create_new_instr(t_instr **head_instr, char *str)
{
	*head_instr = (t_instr *)malloc(sizeof(t_instr));
	if (*head_instr == NULL)
		ft_error(ERROR);
	(*head_instr)->str = str;
	(*head_instr)->next = NULL;
}

void	ft_push_back_new_instr(t_instr **head_instr, char *str)
{
	t_instr	*tmp;
	t_instr	*new;

	if (*head_instr == NULL)
	{
		ft_create_new_instr(head_instr, str);
		(*head_instr)->prev = NULL;
		return ;
	}
	tmp = *head_instr;
	while (tmp->next)
		tmp = tmp->next;
	ft_create_new_instr(&new, str);
	tmp->next = new;
	new->prev = tmp;
}

void	ft_print_instr(t_instr *head)
{
	t_instr	*tmp;

	tmp = head;
	while (tmp)
	{
		write(1, tmp->str, ft_strlen(tmp->str));
		tmp = tmp->next;
	}
}
