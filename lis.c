/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerchi <mcerchi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 14:48:37 by mcerchi           #+#    #+#             */
/*   Updated: 2022/02/26 14:48:39 by mcerchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

int	*ft_lis_util_helper(int max)
{
	int	*val;

	val = (int *) malloc (sizeof(int) * (max + 1));
	if (!val)
		ft_display_exit();
	val[max - 1] = 2147483647;
	return (val);
}

int	*ft_lis_util(int *dst, int *arr, int max, int size)
{
	int	i;
	int	j;
	int	*val;
	int	x;

	j = size;
	val = ft_lis_util_helper(max - 1);
	while (max-- >= 1)
	{
		i = j;
		x = 0;
		while (--i >= 0)
		{
			if (arr[i] == max && ((dst[i] < val[max])
					|| val[max - 1] == 2147483647)
				&& ((dst[i] > val[max - 1]) || (x == 0)))
			{
				val[max - 1] = dst[i];
				j = i;
				x = 1;
			}
		}
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
	j = -1;
	arr = (int *) malloc (sizeof(int) * size);
	if (!arr)
		ft_display_exit();
	while (i < size)
		arr[i++] = 1;
	while (++j < size)
	{
		i = j - 1;
		while (++i < size)
		{
			if (dst[j] < dst[i] && arr[j] == arr[i])
			{
				arr[i] += 1;
				if (arr[i] > *max)
					*max = arr[i];
			}
		}
	}
	return (ft_lis_util(dst, arr, *max + 1, size));
}
