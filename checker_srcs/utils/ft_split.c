#include "../checker.h"

static	size_t	c_word(char const *str, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

static	char	*w_malloc(char const *str, char c)
{
	char	*w;
	int		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	w = (char *)malloc(sizeof(char) * (i + 1));
	if (w == NULL)
		ft_error(ERROR);
	i = 0;
	while (str[i] && str[i] != c)
	{
		w[i] = str[i];
		i++;
	}
	w[i] = '\0';
	return (w);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		a;
	char	**array;

	i = 0;
	a = 0;
	if (s == NULL)
		return (NULL);
	array = (char **)malloc(sizeof(char *) * (c_word(s, c) + 1));
	if (array == NULL)
		return (NULL);
	while (s[a])
	{
		while (s[a] && s[a] == c)
			a++;
		if (s[a] && s[a] != c)
		{
			array[i++] = w_malloc(&s[a], c);
			while (s[a] && s[a] != c)
				a++;
		}
	}
	array[i] = NULL;
	return (array);
}
