/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerchi <mcerchi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 14:49:08 by mcerchi           #+#    #+#             */
/*   Updated: 2022/02/26 14:49:40 by mcerchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

int	ft_the_needed(int min, int max, int size)
{
	int	i;

	if (min > (size / 2))
		min = min - size;
	if (max > (size / 2))
		max = max - size;
	i = ft_min_nbr(max, min);
	return (i);
}

int	ft_the_needed_b(int max, int size)
{
	if (max > (size / 2))
		max = max - size;
	return (max);
}

int	ft_the_needed_a(t_list *stack_a, int cont, int size)
{
	t_list	*tmp;
	int		i;

	tmp = stack_a;
	i = ft_max_or_min(stack_a, cont, size);
	if (i != size + 1)
		return (ft_the_needed_b(i, size));
	while (tmp->next != NULL)
		tmp = tmp->next;
	if (cont < stack_a->content && cont > tmp->content)
		return (0);
	i = 1;
	while (!(cont > stack_a->content && cont < (stack_a->next)->content))
	{
		stack_a = stack_a->next;
		i++;
	}
	return (ft_the_needed_b(i, size));
}

int	*ft_copy_cont(t_list *stack_a, int size)
{
	int	*arr;
	int	i;

	i = 0;
	arr = (int *) malloc (sizeof(int) * size + 1);
	if (!arr)
		ft_display_exit();
	while (stack_a != NULL)
	{
		arr[i++] = (stack_a)->content;
		stack_a = (stack_a)->next;
	}
	return (arr);
}

int	*ft_intcpy(int	*arr, int size)
{
	int	i;
	int	*cpy;

	i = 0;
	cpy = (int *) malloc (sizeof(int) * size);
	if (!arr || !cpy)
		ft_display_exit();
	while (i < size)
	{
		cpy[i] = arr[i];
		i++;
	}
	return (cpy);
}
