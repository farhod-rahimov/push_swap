/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <btammara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:08:23 by btammara          #+#    #+#             */
/*   Updated: 2021/04/09 15:49:56 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

size_t	ft_strlen(const char *s)
{
	unsigned long int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}
