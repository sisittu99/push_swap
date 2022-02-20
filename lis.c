/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:24:53 by mcerchi           #+#    #+#             */
/*   Updated: 2022/02/20 13:25:42 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <stdio.h>

int	*ft_long_lis(int *dst, int *arr, int size)
{
	int	*val;
	int	i;
	int	max;4

	i = 0;
	max = 1;
	while (i < size)
	{
		if (arr[i] > max)
			max = arr[i++];
	}
	val = (char *) malloc (sizeof(char) * max);
	if (!val)
		ft_display_exit();
	i = 0;
	while (max > 0)
	{
		val[max] = dst[]
	}
}

int *longestSubSeq(int *subArr, int n)
{
	int *length;                    //set all length to 0                           //subsequence ending with subArr[0] is 1
	int i;

	length = (int *) malloc (sizeof(int) * (n + 1));
	if (!length)
		ft_display_exit();
	i = 0;
	while (i < n)
	{
		length[i] = 0;
		i++;
	}
	length[0] = 1;
   for (i = 1; i < n; i++) {            //ignore first character, second to all
      for (int j = 0; j < i; j++) {         //subsequence ends with subArr[j]
         if (subArr[j] < subArr[i] && length[j] > length[i])
            length[i] = length[j];
      }
      length[i]++;              //add arr[i]
   }
   return (ft_long_lis(subArr, length, n));
}

/*int	*lis(int *dst, int size)
{
	int	*arr;
	int	i;
	int	j;
	int	x;

	i = 0;
	j = 0;
	x = 0;
	arr = (int *) malloc (sizeof(int) * (size + 1));
	if (!arr)
		ft_display_exit();
	while (i < size)
	{
		arr[i] = 1;
		j = i + 1;
		if (dst[i] < dst[j])
			arr[x++] = dst[-j];
	}
}*/
