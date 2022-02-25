/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:24:53 by mcerchi           #+#    #+#             */
/*   Updated: 2022/02/25 18:15:51 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <stdio.h>

int	*ft_lis_util(int *dst, int *arr, int max, int size)
{
	int	i;
	int	j;
	int	*val;
	int	x;

	i = size;
	j = size;
	x = 0;
	// int cpy = max;
	val = (int *) malloc (sizeof(int) * (max + 1));
	if (!val)
		ft_display_exit();
	// i = -1;
	// printf("\n\n");
	// while(++i < size)
	// 	printf(" %d ", arr[i]);
	// printf("\n\n");
	val[max - 1] = 2147483647;
	while (max >= 1)
	{
		i = j;
		x = 0;
		while (--i >= 0)
		{
			if (arr[i] == max && ((dst[i] < val[max])
					|| val[max - 1] == 2147483647) && ((dst[i] > val[max - 1]) || (x == 0)))
			{
				val[max - 1] = dst[i];
				j = i;
				x = 1;
			}
		}
		max--;
	}
	// i = -1;
	// printf("\nCPY : %d\n", cpy);
	// while (++i < cpy)
	// 	printf(" %d ", val[i]);
	// exit(0);
	// free(arr);
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
	// int *cpy = (int *) malloc (sizeof(int) * size);
	// j = -1;
	// while (++j < size)
	// {
	// 	if (dst[j] < 0)
	// 		cpy[j] = dst[j] * -1;
	// 	else
	// 		cpy[j] = dst[j] * dst[j];
	// }
	j = 0;
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
