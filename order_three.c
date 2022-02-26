/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerchi <mcerchi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 14:49:00 by mcerchi           #+#    #+#             */
/*   Updated: 2022/02/26 14:49:38 by mcerchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

int	return_max_or_min(int cont, int *max_n_min, int size)
{
	if (cont > max_n_min[0])
		return (max_n_min[2]);
	if (cont < max_n_min[1])
		return (max_n_min[3]);
	return (size + 1);
}

int	ft_max_or_min(t_list *stack_a, int cont, int size)
{
	int	max_n_min[5];

	max_n_min[0] = stack_a->content;
	max_n_min[1] = stack_a->content;
	max_n_min[2] = 0;
	max_n_min[3] = 0;
	max_n_min[4] = 1;
	while (stack_a != NULL)
	{
		if (stack_a->content >= max_n_min[0])
		{
			max_n_min[0] = stack_a->content;
			max_n_min[2] = max_n_min[4];
		}
		if (stack_a->content < max_n_min[1])
		{
			max_n_min[1] = stack_a->content;
			max_n_min[3] = max_n_min[4] - 1;
		}
		stack_a = stack_a->next;
		max_n_min[4]++;
	}
	return (return_max_or_min(cont, max_n_min, size));
}

int	ft_min_nbr(int a, int b)
{
	int	a1;
	int	b1;

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

int	ft_max_nbr(int a, int b)
{
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	if (a > b)
		return (a);
	if (b > a)
		return (b);
	else
		return (a);
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
