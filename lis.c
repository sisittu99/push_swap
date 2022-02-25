/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:24:53 by mcerchi           #+#    #+#             */
/*   Updated: 2022/02/25 13:25:54 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <stdio.h>

int	*ft_lis_util(int *dst, int *arr, int max, int size)
{
	int	i;
	int	j;
	int	*val;

	i = size;
	j = size;
	val = (int *) malloc (sizeof(int) * (max + 1));
	if (!val)
		ft_display_exit();
	val[max - 1] = -1;
	while (max >= 1)
	{
		i = j;
		while (--i >= 0)
		{
			if (arr[i] == max && ((dst[i] < val[max]) || val[max - 1] == -1))
			{
				val[max - 1] = dst[i];
				j = i;
			}
		}
		max--;
	}
	free(arr);
	return (val);
}

int	*ft_define_lis(int *dst, int size, int *max)
{
	int	*arr;
	int	i;
	int	j;

	i = 0;
	j = 0;
	arr = (int *) malloc (sizeof(int) * size);
	if (!arr)
		ft_display_exit();
	while (i < size)
		arr[i++] = 1;
	while (j < size)
	{
		i = j;
		while (i < size)
		{
			if (dst[j] < dst[i] && arr[j] == arr[i])
			{
				arr[i] += 1;
				if (arr[i] > *max)
					*max = arr[i];
			}
			i++;
		}
		j++;
	}
	return (ft_lis_util(dst, arr, *max, size));
}
