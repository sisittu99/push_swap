/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:24:53 by mcerchi           #+#    #+#             */
/*   Updated: 2022/02/24 14:16:29 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <stdio.h>

int	*ft_lis_util(int *dst, int *arr, int max, int size)
{
	int	i;
	int	j;
	int	*val;
	int	cpy;

	i = size;
	j = size - 1;
	cpy = max;
	val = (int *) malloc (sizeof(int) * max);
	if (!val)
		ft_display_exit();
	val[max - 1] = size + 1;
	while (max >= 1)
	{

		i = j;
		while (--i >= 0)
		{
			if (arr[i] == max && ((dst[i] < val[max]) || val[max - 1] == size + 1))
			{
				val[max - 1] = dst[i];
				j = i;
			}
		}
		max--;
	}
	// i = max - 1;
	// val[i--] = dst[j--];

	// max--;
	// while (j >= 0 && i >= 0)
	// {
	// 	if (arr[j] == max && dst[j] < val[max])
	// 	{
	// 		val[i] = dst[j];
	// 		max--;
	// 		i--;
	// 	}
	// 	j--;
	// }
	// i = -1;
	// printf("\nVAL :\t");
	// while (++i < cpy)
	// 	printf(" %d ", val[i]);
	// exit(0);
	return (val);
}

// int	*ft_long_lis(int *dst, int *arr, int size, int *ret)
// {
// 	int	i;
// 	int	max;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	max = 1;
// 	while (i < size)
// 	{
// 		if (arr[i] > max)
// 		{
// 			max = arr[i];
// 			j = i;
// 		}
// 		i++;
// 	}
// 	*ret = max;
// 	return (ft_lis_util(dst, arr, max, j));
// }

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
	// i = -1;
	// printf("ARR LIS:\n");
	// while (++i < size)
	// 	printf(" %d\t%d\n", arr[i], dst[i]);
	// printf ("\nMAX : %d", *max);
	return (ft_lis_util(dst, arr, *max, size));
}
