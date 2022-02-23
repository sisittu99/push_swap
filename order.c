/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerchi <mcerchi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:56:05 by mcerchi           #+#    #+#             */
/*   Updated: 2022/02/22 16:38:42 by mcerchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/*
*	contatori nella prox funzione:
*	#0:	int	pos_first;
*	#1:	int	pos_last;
*	#2:	int	pos;
*	#3:	int	i;
*/

int	ft_best_nbr_a(t_list *stack_a, int size, int *arr, int max)
{
	int	pos[4];

	pos[0] = -1;
	pos[1] = 0;
	pos[2] = 0;
	pos[3] = 0;
	while (stack_a != NULL)
	{
		pos[3] = 0;
		while (stack_a->content != arr[pos[3]] && pos[3] <= max - 1)
		{
			if (pos[3] == max - 1)
			{
				pos[1] = pos[2];
				if (pos[0] == -1)
					pos[0] = pos[2];
			}
			pos[3]++;
		}
		stack_a = stack_a->next;
		pos[2]++;
	}
	if (pos[0] == -1)
		return (size + 1);
	return (ft_the_needed(pos[0], pos[1], size));
}

int	ft_best_comb(int *arr_a, int *arr_b, int size)
{
	int	*tmp;
	int	i;
	int	pos;

	i = -1;
	pos = 0;
	tmp = (int *) malloc (sizeof(int) * size);
	if (!tmp || !arr_a || !arr_b)
		ft_display_exit();
	while (++i < size)
	{
		if (arr_a[i] < 0)
			arr_a[i] *= -1;
		if (arr_b[i] < 0)
			arr_b[i] *= -1;
		if (arr_a[i] > 0 && arr_b[i] > 0)
			tmp[i] = ft_max_nbr(arr_a[i], arr_b[i]);
		else
			tmp[i] = arr_a[i] + arr_b[i];
	}
	i = 0;
	while (++i < size)
		if (tmp[i] < tmp[pos])
			pos = i;
	return (pos);
}

int	ft_move_a(int a, int b, t_list **stack_a, t_list **stack_b)
{
	if (a < 0 && b < 0)
	{
		while (a < 0 && b < 0)
		{
			ft_rrr(stack_a, stack_b);
			a++;
			b++;
		}
	}
	if (a > 0 && b > 0)
	{
		while (a > 0 && b > 0)
		{
			ft_rr(stack_a, stack_b);
			a--;
			b--;
		}
	}
	if (a < 0)
		while (a++ < 0)
			ft_rra(stack_a);
	else if (a > 0)
		while (a-- > 0)
			ft_ra(stack_a);
	return (b);
}

int	ft_best_nbr_b(t_list **stack_b, int size_b, t_list **stack_a, int size_a)
{
	int		*arr_b;
	int		*arr_a;
	t_list	*tmp_b;
	int		i;

	i = -1;
	tmp_b = *stack_b;
	arr_a = (int *) malloc (sizeof(int) * size_b);
	arr_b = (int *) malloc (sizeof(int) * size_b);
	if (!arr_b || !arr_a)
		ft_display_exit();
	while (++i < size_b)
		arr_b[i] = ft_the_needed_b(i, size_b);
	i = -1;
	while (++i < size_b && tmp_b != NULL)
	{
		arr_a[i] = ft_the_needed_a(*stack_a, tmp_b->content, size_a);
		tmp_b = tmp_b->next;
	}
	i = ft_best_comb(ft_intcpy(arr_a, size_a),
			ft_intcpy(arr_b, size_b), size_b);
	return (ft_move_a(arr_a[i], arr_b[i], stack_a, stack_b));
}

void	ft_search_min(t_list **stack_a, int size)
{
	int		pos;
	int		pos_min;
	int		min;
	t_list	*tmp;

	pos_min = 0;
	pos = 0;
	tmp = *stack_a;
	min = tmp->content;
	while (pos < size)
	{
		if (min > tmp->content)
		{
			min = tmp->content;
			pos_min = pos;
		}
		tmp = tmp->next;
		pos++;
	}
	tmp = NULL;
	pos = ft_the_needed_b(pos_min, size);
	ft_move_a(pos, 0, stack_a, &tmp);
}
