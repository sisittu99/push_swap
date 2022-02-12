/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerchi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:48:41 by mcerchi           #+#    #+#             */
/*   Updated: 2022/01/21 12:23:57 by mcerchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		lenght;
	char	*dest;

	lenght = ft_strlen(s1);
	dest = (char *) malloc ((lenght + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	ft_memmove(dest, s1, lenght);
	dest[lenght] = '\0';
	return (dest);
}
