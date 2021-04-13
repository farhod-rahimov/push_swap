/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <btammara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 18:02:37 by btammara          #+#    #+#             */
/*   Updated: 2021/04/09 15:49:54 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*go;

	go = lst;
	if (lst)
	{
		while (go->next != NULL)
			go = go->next;
	}
	return (go);
}
