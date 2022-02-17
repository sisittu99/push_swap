/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerchi <mcerchi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:53:52 by mcerchi           #+#    #+#             */
/*   Updated: 2022/02/17 14:19:287 by mcerchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./libft/libft.h"
#include "push_swap.h"

void	ft_write_lst(t_list **stack_a, int argc, char **argv)
{
	t_list	*tmp;
	int		i;

	i = 1;
	tmp = NULL;
	while (i < argc)
	{
		tmp = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(stack_a, tmp);
		ft_lstcheck(*stack_a, tmp->content);
		i++;
	}
	ft_lst_order(stack_a);
}

void	ft_move_to_b(t_list **stack_a, t_list **stack_b, int start, int end)
{
	int	i;
	int size;

	size = ft_lstsize(*stack_a);
	i = ft_choose_best_nbr_a(stack_a, size, start, end);
	while (i != size + 1)
	{
		if (i < 0)
			while (i++ <= 0)
				ft_rra(stack_a);
		else if (i > 0 && i < size)
			while (i-- > 0)
				ft_ra(stack_a);
		ft_pb(stack_a, stack_b);
		i = ft_choose_best_nbr_a(stack_a, size, start, end);
	}
	while (*stack_b != NULL)
	{
		i = ft_choose_best_nbr_b(stack_b, ft_lstsize(*stack_b));
		if (i < 0)
			while (i++ <= 0)
				ft_rrb(stack_b);
		else if (i > 0)
			while (i-- > 0)
				ft_rb(stack_b);
		ft_pa(stack_b, stack_a);
	}
}

void	ft_lst_split(t_list **stack_a, t_list **stack_b, int size)
{
	int	*dst;
	int	i;
	int n;

	i = 0;
	n = 1;
	while (size / n > 46)
		n++;
	dst = ft_copy_cont(*stack_a, size);
	lst_display(*stack_a);
	dst = quicksort(dst, 0, size);
	printf("dst ordinato: \t %d %d %d", dst[0], dst[1], dst[2]);
	while (i != n)
	{
		ft_move_to_b(stack_a, stack_b, dst[(size / n) * i], dst[(size / n) * (i + 1)]);
		i++;
	}
	lst_display(*stack_a);
	free (dst);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 3)
		ft_display_exit();
	ft_write_lst(&stack_a, argc, argv);
	lst_display(stack_a);
	size = ft_lstsize(stack_a);
	//creo una lista dove mi segno la posizione che il numero dovrebbe avere.
	ft_lst_split(&stack_a, &stack_b, size);
	lst_display(stack_a);
	return (0);
}
