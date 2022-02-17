/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerchi <mcerchi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:56:05 by mcerchi           #+#    #+#             */
/*   Updated: 2022/02/17 12:35:46 by mcerchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_copy_cont(t_list **stack_a, int size)
{
	int	*arr;
	int	i;

	i = 0;
	arr = (int *) malloc (sizeof(int) * size + 1);
	if (!arr)
		ft_display_exit();
	while(stack_a != NULL)
	{
		arr[i++] = stack_a->content;
		stack_a = stack_a->next;
	}
	return (arr);
}

int	ft_min_nbr(int a, int b)
{
	int a1;
	int b1;

	a1 = a;
	b1 = b;
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	if (a == b)
		return (a1);
	if (a < b)
		return (a1);
	return (b1);
}

int ft_the_needed(int min, int max, int size)
{
	int i;

	if (min > (size / 2))
		min = min - size;
	if (max > (size / 2))
		max = max - size;
	i = ft_min_nbr(max, min);
	return (i);
}


int	ft_choose_best_nbr(t_list **stack_a, int mid)
{
	int	max;
	int	pos_max;
	int	min;
	int	pos_min;
	int	pos;

	max = stack_a->content;
	min = stack_a->content;
	pos_max = 0;
	pos_min = 0;
	pos = 0;
	while (stack_a != NULL)
	{
		stack_a = stack_a->next;
		if (stack_a->content > max)
		{
			max = stack_a->content;
			pos_max = pos;
		}
		else if (stack_a->content < min)
		{
			min = stack_a->content;
			pos_min = pos;
		}
		pos++;
	}
	return (ft_the_needed(pos_min, pos_max, size));
}
