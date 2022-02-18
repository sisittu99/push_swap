/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:53:52 by mcerchi           #+#    #+#             */
/*   Updated: 2022/02/18 13:50:50 by fdrudi           ###   ########.fr       */
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
// printf("test su ft_write_lst\n\nstampa di argc:\t\t%d", argc);fflush(stdout);
// printf("\nstampa di ")
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
	int	size;

	size = ft_lstsize(*stack_a) - 1;
	printf("\nMove To B List:\n");
	lst_display(*stack_a);
	printf("\nStart: %d\t End: %d\n", start, end);
	i = ft_choose_best_nbr_a(*stack_a, size, start, end);
	while (i != size + 1)
	{
		printf("\nIndicatore Mosse A: %d\n", i);
		if (i < 0)
			while (i++ <= 0)
				ft_rra(stack_a);
		else if (i > 0 && i < size)
			while (i-- > 0)
				ft_ra(stack_a);
		ft_pb(stack_a, stack_b);
		i = ft_choose_best_nbr_a(*stack_a, size, start, end);
	}
	printf("\nIndicatore Mosse A: %d\n", i);
	printf("\nSize: %d\n", size);
	printf("\nPost Move To B List:\n");
	lst_display(*stack_a);
	printf("\nB ListPost Move To B List:\n");
	lst_display(*stack_b);
	while (*stack_b != NULL)
	{
		i = ft_choose_best_nbr_b(*stack_b, ft_lstsize(*stack_b));
		printf("\nIndicatore Mosse B: %d\n", i);
		if (i < 0)
			while (i++ < 0)
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
	int	n;

	i = 0;
	n = 1;
	while (size / n > 46)
		n++;
	dst = ft_copy_cont(*stack_a, size);
	printf("\nDest Copy: ");
	i = -1;
	while (i++ < size)
		printf("%d ", dst[i]);
	i = 0;
	printf("\nSplit lista:\n");
	lst_display(*stack_a);
	dst = quicksort(dst, 0, size);
	while (i != n)
	{
		ft_move_to_b(stack_a, stack_b, dst[(size / n) * i], dst[(size / n) * (i + 1)]);
		i++;
	}
	free (dst);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;
	char	**arg;

	stack_a = NULL;
	stack_b = NULL;
	size = 0;
	if (argc < 2)
		ft_display_exit();
	if (argc == 2)
	{
		arg = ft_split(argv[1], ' ');
		while (arg[size] != NULL)
			size++;
		ft_write_lst(&stack_a, size, arg);
	}
	else
		ft_write_lst(&stack_a, argc, argv);
	size = ft_lstsize(stack_a) - 1;
	ft_lst_split(&stack_a, &stack_b, size);
	printf("\nReturn List:");
	lst_display(stack_a);
	return (0);
}
