#include "checker.h"

static	t_instr *ft_push_back(t_instr *prev);

void    ft_get_instructions(t_instr *instructions_head)
{
	t_instr	*current;
	char	c;
	int		i;

	i = 0;
	current = instructions_head;
	current->next = NULL;
	while (read(0, &c, 1))
	{
		if (c == '\n')
		{
			if (i > 3)
				ft_error(ERROR);
			current->str[i++] = c;
			current->str[i] = '\0';
			current = ft_push_back(current);
			i = 0;
			continue ;
		}
		else
			current->str[i++] = c;
	}
	ft_check_if_instr_are_correct(instructions_head);
	// ft_printos(instructions_head);
}

void	ft_check_if_instr_are_correct(t_instr *instructions_head)
{
	char	**possible_instr;
	t_instr	*tmp;
	size_t	i;

	possible_instr = ft_get_possible_instr();
	tmp = instructions_head;
	i = 0;
	while (tmp)
	{
		while (possible_instr[i])
		{
			if (!ft_strcmp(tmp->str, possible_instr[i]))
				break ;
			i++;
		}
		if ((i == 11 && ft_strcmp(tmp->str, "")) || (!ft_strcmp(tmp->str, "") && tmp->next))
			ft_error(ERROR);
		i = 0;
		tmp = tmp->next;
	}
	ft_free_two_dimensional_array(possible_instr);
}

char	**ft_get_possible_instr(void)
{
	char	**p_instr;

	p_instr = (char **)malloc(sizeof(char *) * 12);
	if (p_instr == NULL)
		ft_error(ERROR);
	p_instr[0] = ft_strdup("sa\n");
	p_instr[1] = ft_strdup("sb\n");
	p_instr[2] = ft_strdup("ss\n");
	p_instr[3] = ft_strdup("pa\n");
	p_instr[4] = ft_strdup("pb\n");
	p_instr[5] = ft_strdup("ra\n");
	p_instr[6] = ft_strdup("rb\n");
	p_instr[7] = ft_strdup("rr\n");
	p_instr[8] = ft_strdup("rra\n");
	p_instr[9] = ft_strdup("rrb\n");
	p_instr[10] = ft_strdup("rrr\n");
	p_instr[11] = NULL;
	return (p_instr);
}

t_instr *ft_push_back(t_instr *prev)
{
	t_instr *new_element;

    new_element = (t_instr *)malloc(sizeof(t_instr));
    if (new_element == NULL)
        ft_error(ERROR);
    prev->next = new_element;
    new_element->next = NULL;
	ft_bzero(new_element->str, sizeof(char) * 5);
    return (new_element);
}

void    ft_printos(t_instr *head)
{
    while (head)
    {
		if (ft_strcmp(head->str, ""))
        	printf("%s", head->str);
        head = head->next;
    }
}