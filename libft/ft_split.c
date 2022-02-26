/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerchi <mcerchi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:21:04 by mcerchi           #+#    #+#             */
/*   Updated: 2022/02/26 14:51:30 by mcerchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nb_words(const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*s != '\0')
	{
		if ((*s != c) && (j == 0))
		{
			j = 1;
			i++;
		}
		if (*s == c)
			j = 0;
		s++;
	}
	return (i);
}

static char	**wds_assign(const char *s, char c, char **dest, size_t len)
{
	size_t	i;
	size_t	x;
	int		j;

	i = 0;
	x = 0;
	j = -1;
	while (i <= len)
	{
		if (s[i] != c && j < 0)
			j = i;
		else if ((s[i] == c || i == len) && j >= 0)
		{
			dest[x++] = ft_substr(s, j, (i - j));
			j = -1;
		}
		i++;
	}
	dest[x] = 0;
	return (dest);
}

char	**ft_split(const char *s, char c)
{
	char	**dest;
	size_t	len;
	int		i;

	i = 0;
	if (s[0] == '\0')
		exit(0);
	while (s[i] <= 32 && s[i] != '\0')
	{
		i++;
		if (s[i] == '\0')
			exit(0);
	}
	len = (ft_strlen(s));
	dest = (char **) malloc ((nb_words(s, c) + 1) * sizeof(char *));
	if (!dest)
		return (NULL);
	wds_assign(s, c, dest, len);
	return (dest);
}
