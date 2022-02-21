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
	//printf("controllo in copy_cont:\t"); lst_display(stack_a);
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
	// i = -1;
	// printf("\nArray Copy: ");
	// while (i++ < size)
	// 	printf("%d ", arr[i]);
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
	printf("\n size : %d\n", size);
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
	printf("\n pos_first : %d\tpos_last : %d\n", pos_first, pos_last);
	if (pos_first == -1)
		return (size + 1);
	return (ft_the_needed(pos_first, pos_last, size));
}

int	ft_the_needed_a(*stack_a, int cont, int size)
{
	t_list	*tmp;
	int	i;

	tmp = stack_a;
	while (tmp->next != NULL)
		tmp = tmp->next;
	i = 0;
	if (cont < stack_a->content && cont > tmp->content)
		return (0);
	while (!(cont > stack_a->content && cont < (stack_a->next)->content))
	{
		stack_a = stack_a->next;
		i++;
	}
	i++;
	return (ft_the_needed_b(i, size));
}

int	ft_choose_best_nbr_b(t_list *stack_b, int size_b, t_list *stack_a, int size_a)
{
	//definiamo array  di appoggio
	int	*arr_b;
	int	*arr_a;
	int	i;
	int	j;
	//chiama 2 funzioni (ok)
	//1 per the needed di B (ok)
	//1 per the needed di A rispetto val B (ok)
	//analisi mosse doppie
	//Scelta migliore
	//display mosse doppie
	//display mosse singole A
	//riduciamo il numero togliendo le mosse effettuate

	i = 0;
	arr_a = (int *) malloc (sizeof(int) * size_a);
	arr_b = (int *) malloc (sizeof(int) * size_b);
	if (!arr_b || !arr_a)
		ft_display_exit();
	while (i < size_b)
	{
		arr_b[i] = ft_the_needed_b(i, size_b);
		i++;
	}
	i = 0;
	while (i < size_b)
	{
		arr_a[i] = ft_the_needed_a(stack_a, stack_b->content, size_a);
		stack_b = stack_b->next;
		i++;
	}
	//calcolare in un array il numero (positivo!) di mosse che iasogna fare:
	//se i due numeri sono entrambi positivi o negativi, va preso il maggiore dei due
	// altrimenti il numero di mosse sarà banalmente la somma (sempre in pos).

	//le mosse verrano applicate in una funzione esterna richiamata qui.
	//il numero da ritornare sarà la posizione del numero scelto.
	i = ft_cazzimiei
	j = ft_mosse_di_a
	return (j);
}
