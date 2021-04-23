#include "../push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (1);
	if (ft_strlen(s1) != ft_strlen(s2))
		return (1);
	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}
