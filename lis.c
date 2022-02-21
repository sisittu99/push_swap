/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:24:53 by mcerchi           #+#    #+#             */
/*   Updated: 2022/02/21 11:11:220 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <stdio.h>

int	*ft_long_lis(int *dst, int *arr, int size, int *ret)
{
	int	*val;
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
	val = (int *) malloc (sizeof(int) * max + 1);
	if (!val)
		ft_display_exit();
	*ret = max;
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
	i = 0;
	printf("\nLIS : ");
	while (i < 5)
	{
		printf(" %d ", val[i]);
		i++;
	}
	return (val);
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
