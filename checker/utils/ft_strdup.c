#include "../checker.h"

char	*ft_strdup(const char *s1)
{
	char					*p;
	unsigned long long int	i;
	unsigned long long int	a;

	i = 0;
	a = 0;
	while (s1[i] != '\0')
		i++;
	if ((p = (char *)malloc((i + 1) * sizeof(char))))
	{
		while (a < i)
		{
			p[a] = s1[a];
			a++;
		}
		p[i] = '\0';
		return (p);
	}
	return (NULL);
}
