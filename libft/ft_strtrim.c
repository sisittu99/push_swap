/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerchi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:50:59 by mcerchi           #+#    #+#             */
/*   Updated: 2022/01/21 12:24:33 by mcerchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	first_char(const char *s1, const char *set)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{	
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

static int	last_char(const char *s1, const char *set)
{
	size_t	i;
	size_t	j;
	size_t	len;

	len = ft_strlen(s1);
	i = ft_strlen(s1) - 1;
	j = -1;
	while (++j < len)
	{
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		i--;
	}
	return (i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*cp;
	int		fc;
	int		lc;
	size_t	i;

	i = 0;
	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return ((char *)s1);
	fc = first_char(s1, set);
	lc = last_char(s1, set);
	if (fc >= lc)
		return (ft_strdup(""));
	cp = (char *) malloc (sizeof(char) * (lc - fc + 1));
	if (cp == NULL)
		return (NULL);
	while (fc < lc)
		cp[i++] = s1[fc++];
	cp[i] = '\0';
	return (cp);
}
