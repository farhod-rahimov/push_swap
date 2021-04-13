/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <btammara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 13:25:30 by btammara          #+#    #+#             */
/*   Updated: 2021/04/09 15:49:51 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

static	long long int	ft_atoi_ft(const char *str, long long int i)
{
	while (str[i])
	{
		if (str[i] == '\t' || str[i] == '\n' || str[i] == '\v')
			i++;
		else if (str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
			i++;
		else
			break ;
	}
	if ((str[i] < '0' || str[i] > '9') && str[i] != '-' && str[i] != '+')
		return (-2);
	return (i);
}

static	long long int	ft_atoi_min(const char *s)
{
	long long int	i;
	long long int	ret_min;
	long long int	ret;

	i = 1;
	ret = 0;
	ret_min = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		if (s[i] >= '0' && s[i] <= '9')
			ret_min = ret_min * 10 + (s[i++] - 48);
		else
			break ;
	}
	if (ret_min == 2147483648)
		return (-2147483648);
	return (ret = ret_min * -1);
}

long long int	ft_atoi(const char *str)
{
	long long int	i;
	long long int	ii;
	long long int	a;
	long long int	ret;

	i = 0;
	ret = 0;
	if ((ii = ft_atoi_ft(str, i)) == -2)
		return (0);
	i = ii;
	while (str[i])
	{
		a = i;
		if ((str[i] < '0' || str[i] > '9') && str[a] != '-' && str[a] != '+')
			break ;
		else if (str[a] == '-')
		{
			ret = ft_atoi_min(str + a);
			break ;
		}
		else if (str[a] == '+')
		{
			ret = ft_atoi_min(str + a) * -1;
			break ;
		}
		ret = ret * 10 + (str[i++] - 48);
		if (str[i] < '0' || str[i] > '9')
			break ;
	}
	if (ret > 2147483647 || ret < -2147483648 || ft_strlen(str) > 11)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	return (ret);
}
