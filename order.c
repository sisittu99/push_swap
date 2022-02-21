/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:56:05 by mcerchi           #+#    #+#             */
/*   Updated: 2022/02/21 11:43:343 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	*ft_copy_cont(t_list *stack_a, int size)
{
	int	*arr;
	int	i;

	i = 0;
	arr = (int *) malloc (sizeof(int) * size + 1);
	if (!arr)
		ft_display_exit();
	while(stack_a != NULL)
	{
		arr[i++] = (stack_a)->content;
		stack_a = (stack_a)->next;
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

int	ft_the_needed_b(int max, int size)
{
	if (max > (size / 2))
		max = max - size;
	return (max);
}

int	ft_choose_best_nbr_a(t_list *stack_a, int size, int *arr, int max)
{
	int	pos_first;
	int	pos_last;
	int	pos;
	int	i;

	pos_first = -1;
	pos_last = 0;
	pos = 0;
	i = 0;
	while (stack_a != NULL)
	{
		i = 0;
		while (stack_a->content != arr[i] && i <= max - 1)
		{
			if (i == max - 1)
			{
				pos_last = pos;
				if (pos_first == -1)
					pos_first = pos;
			}
			i++;
		}
		stack_a = stack_a->next;
		pos++;
	}
	if (pos_first == -1)
		return (size + 1);
	return (ft_the_needed(pos_first, pos_last, size));
}

int	ft_max_or_min(t_list *stack_a, int cont, int size)
{
	int	pos;
	int	min;
	int	max;
	int	pos_max;
	int	pos_min;

	max = stack_a->content;
	min = stack_a->content;
	pos_max = 0;
	pos_min = 0;
	pos = 1;
	while (stack_a != NULL)
	{
		if (stack_a->content > max)
		{
			max = stack_a->content;
			pos_max = pos;
		}
		if (stack_a->content < min)
		{
			min = stack_a->content;
			pos_min = pos;
		}
		stack_a = stack_a->next;
		pos++;
	}
	if (cont > max)
		return (pos_max);
	if (cont < min)
		return (pos_min);
	return (size + 1);
}

int	ft_the_needed_a(t_list *stack_a, int cont, int size)
{
	t_list	*tmp;
	int		i;

	tmp = stack_a;
	i = ft_max_or_min(stack_a, cont, size);
	if (i != size + 1)
		return(ft_the_needed_b(i, size));
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

int	ft_max_nbr(int a, int b)
{
	if (a > b)
		return (a);
	if (b > a)
		return (b);
	else
		return (a);
}

int	ft_best_comb(int *arr_a, int *arr_b, int size)
{
	int	*tmp;
	int	i;
	int	pos;

	i = 0;
	pos = 0;
	tmp = (int *) malloc (sizeof(int) * size);
	if (!tmp)
		ft_display_exit();
	while (i < size)
	{
		if (arr_a[i] < 0)
			arr_a[i] *= -1;
		if (arr_b[i] < 0)
			arr_b[i] *= -1;
		if (arr_a[i] > 0 && arr_b[i] > 0)
			tmp[i] = ft_max_nbr(arr_a[i], arr_b[i]);
		else
			tmp[i] = arr_a[i] + arr_b[i];
		i++;
	}
	i = 1;
	while (i < size)
	{
		if (tmp[i] < tmp[pos])
			pos = i;
		i++;
	}
	return (pos);
}

int	ft_move_a(int a, int b, t_list **stack_a, t_list **stack_b)
{
	if (a < 0 && b < 0)
		while (a++ < 0 && b++ < 0)
			ft_rrr(stack_a, stack_b);
	if (a > 0 && b > 0)
		while (a-- > 0 && b-- > 0)
			ft_rr(stack_a, stack_b);
	if (a < 0)
			while (a++ < 0)
				ft_rra(stack_a);
	else if (a > 0)
			while (a-- > 0)
				ft_ra(stack_a);
	return (b);
}

int	ft_choose_best_nbr_b(t_list **stack_b, int size_b, t_list **stack_a, int size_a)
{
	//definiamo array  di appoggio
	int		*arr_b;
	int		*arr_a;
	t_list	*tmp_b;
	int		i;
	//chiama 2 funzioni (ok)
	//1 per the needed di B (ok)
	//1 per the needed di A rispetto val B (ok)
	//analisi mosse doppie
	//Scelta migliore
	//display mosse doppie
	//display mosse singole A
	//riduciamo il numero togliendo le mosse effettuate

	i = 0;
	tmp_b = *stack_b;
	arr_a = (int *) malloc (sizeof(int) * size_b);
	arr_b = (int *) malloc (sizeof(int) * size_b);
	if (!arr_b || !arr_a)
		ft_display_exit();
	printf("\nARR B : ");
	while (i < size_b)
	{
		arr_b[i] = ft_the_needed_b(i, size_b);
		printf(" %d ", arr_b[i]);
		i++;
	}
	i = 0;
	printf("\nARR A : ");
	while (i < size_b && tmp_b != NULL)
	{
		arr_a[i] = ft_the_needed_a(*stack_a, tmp_b->content, size_a);
		 printf(" %d ", arr_a[i]);
		tmp_b = tmp_b->next;
		i++;
	}

	//calcolare in un array il numero (positivo!) di mosse che bisogna fare:
	//se i due numeri sono entrambi positivi o negativi, va preso il maggiore dei due
	//altrimenti il numero di mosse sarà banalmente la somma (sempre in pos).

	//le mosse verrano applicate in una funzione esterna richiamata qui.
	//il numero da ritornare sarà la posizione del numero scelto.
	i = ft_best_comb(arr_a, arr_b, size_b);
	return (ft_move_a(arr_a[i], arr_b[i], stack_a, stack_b));
}
