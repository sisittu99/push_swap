/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerchi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:50:51 by mcerchi           #+#    #+#             */
/*   Updated: 2022/01/21 12:24:30 by mcerchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;

	len = ft_strlen(s);
	if (!len && c == '\0')
		return ((char *)s);
	s += len - 1;
	if (c == '\0')
		return (ft_strchr(s, '\0'));
	while (len--)
	{
		if (*s == (char) c)
			return ((char *) s);
		s--;
	}
	return (0);
}
