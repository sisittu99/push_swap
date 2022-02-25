/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:44:39 by mcerchi           #+#    #+#             */
/*   Updated: 2022/02/25 19:11:31 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(int *))
{
	t_list	*tmp;

	tmp = lst;
	if (lst != NULL)
	{
		lst = tmp->next;
		del(&tmp->content);
		free(tmp);
	}
}
