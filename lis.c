/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:24:53 by mcerchi           #+#    #+#             */
/*   Updated: 2022/02/22 13:13:10 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <stdio.h>

int	*ft_lis_util(int *dst, int *arr, int max, int j)
{
	int	i;
	int	*val;

	i = 0;
	val = (int *) malloc (sizeof(int) * max + 1);
	if (!val)
		ft_display_exit();
	i = max - 1;
	val[i--] = dst[j--];
	max--;
	while (j >= 0 && i >= 0)
	{
		if (arr[j] == max && dst[j] < val[max])
		{
			val[i] = dst[j];
			max--;
			i--;
		}
		j--;
	}
	return (val);
}

int	*ft_long_lis(int *dst, int *arr, int size, int *ret)
{
	int	i;
	int	max;
	int	j;

	i = 0;
	j = 0;
	max = 1;
	while (i < size)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			j = i;
		}
		i++;
	}
	*ret = max;
	return (ft_lis_util(dst, arr, max, j));
}

int	*ft_define_lis(int *dst, int size, int *max)
{
	int	*arr;
	int	i;
	int	j;

	arr = (int *) malloc (sizeof(int) * size);
	if (!arr)
		ft_display_exit();
	i = 1;
	arr[0] = 1;
	while (i < size)
	{
		arr[i] = 1;
		j = 0;
		while (j < i)
		{
			if (dst[i] > dst[j] && arr[i] < arr[j] + 1)
				arr[i] = arr[j] + 1;
			j++;
		}
		i++;
	}
	return (ft_long_lis(dst, arr, j, max));
}
