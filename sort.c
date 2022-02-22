/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:23:41 by fdrudi            #+#    #+#             */
/*   Updated: 2022/02/22 17:57:08 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./libft/libft.h"
#include "push_swap.h"

void	ft_sort_three(t_list **stack_a)
{
	int		i;
	int		j;
	int		x;
	t_list	*tmp;

	tmp = NULL;
	i = 0;
	j = 0;
	x = 0;
	while (!(i < j && j < x && x > i))
	{
		tmp = *stack_a;
		i = tmp->content;
		tmp = tmp->next;
		j = tmp->content;
		tmp = tmp->next;
		x = tmp->content;
		if ((i > j && j < x && x > i)
			|| (i > j && j > x && x < i) || (i < j && j > x && x > i))
			ft_sa(stack_a);
		if (i > j && j < x && x < i)
			ft_ra(stack_a);
		if (i < j && j > x && x < i)
			ft_rra(stack_a);
	}
}

void	ft_sort_five(t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = 2;
	while (i-- > 0)
		ft_pb(stack_a, stack_b);
	ft_sort_three(stack_a);
	ft_move_to_a(stack_a, stack_b);
	ft_search_min(stack_a, ft_lstsize(*stack_a));
}

void	ft_move_to_a(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	size_a;
	int	size_b;

	i = 0;
	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	while (*stack_b != NULL)
	{
		i = ft_best_nbr_b(stack_b, size_b, stack_a, size_a);
		if (i < 0)
			while (i++ < 0)
				ft_rrb(stack_b);
		else if (i > 0)
			while (i-- > 0)
				ft_rb(stack_b);
		ft_pa(stack_b, stack_a);
		size_a++;
		size_b--;
	}
}

void	ft_check_b(t_list **stack_b, int cont)
{
	int	i;
	int	size;

	size = ft_lstsize(*stack_b);
	i = 0;
	if (*stack_b == NULL)
		return ;
	i = ft_the_needed_a(*stack_b, cont, size);
	if (i < 0)
		while (i++ < 0)
			ft_rb(stack_b);
	else if (i > 0 && i != size + 1)
		while (i-- > 0)
			ft_rrb(stack_b);
}

void	ft_move_to_b(t_list **stack_a, t_list **stack_b, int *arr, int max)
{
	int	i;
	int	size_a;

	size_a = ft_lstsize(*stack_a);
	i = ft_best_nbr_a(*stack_a, size_a, arr, max);
	while (i != size_a + 1)
	{
		if (i < 0)
			while (i++ < 0)
				ft_rra(stack_a);
		else if (i > 0 && i < size_a)
			while (i-- > 0)
				ft_ra(stack_a);
		ft_check_b(stack_b, (*stack_a)->content);
		ft_pb(stack_a, stack_b);
		i = ft_best_nbr_a(*stack_a, --size_a, arr, max);
	}
}
