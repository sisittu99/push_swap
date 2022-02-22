/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:53:52 by mcerchi           #+#    #+#             */
/*   Updated: 2022/02/21 11:15:1 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./libft/libft.h"
#include "push_swap.h"

void	ft_write_lst(t_list **stack_a, int argc, char **argv, int i)
{
	t_list	*tmp;

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

void	ft_move_to_b(t_list **stack_a, t_list **stack_b, int *arr, int max)
{
	int	i;
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(*stack_a);
	i = ft_choose_best_nbr_a(*stack_a, size_a, arr, max);
	while (i != size_a + 1)
	{
		if (i < 0)
			while (i++ < 0)
				ft_rra(stack_a);
		else if (i > 0 && i < size_a)
			while (i-- > 0)
				ft_ra(stack_a);
		ft_pb(stack_a, stack_b);
		i = ft_choose_best_nbr_a(*stack_a, --size_a, arr, max);
	}
	size_b = ft_lstsize(*stack_b);
	while (*stack_b != NULL)
	{
		printf("\nstack A : ");
		lst_display(*stack_a);
		printf("\nstack B : ");
		lst_display(*stack_b);
		i = ft_choose_best_nbr_b(stack_b, size_b, stack_a, size_a);
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
	printf("\nstack A : ");
	lst_display(*stack_a);
	printf("\nstack B : ");
	lst_display(*stack_b);
	ft_search_min(stack_a, ft_lstsize(*stack_a));
	printf("\nstack A : ");
	lst_display(*stack_a);
	printf("\nstack B : ");
	lst_display(*stack_b);
	exit(0);
}

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

void	ft_lst_split(t_list **stack_a, t_list **stack_b, int size)
{
	int	*dst;
	int	*arr;
	int	i;

	i = 0;
	if (size == 3)
	{
		ft_sort_three(stack_a);
		return ;
	}
	dst = ft_copy_cont(*stack_a, size);
	arr = ft_define_lis(dst, size, &i);
	ft_move_to_b(stack_a, stack_b, arr, i);
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
		ft_write_lst(&stack_a, size, arg, 0);
	}
	else if (argc >= 3)
		ft_write_lst(&stack_a, argc, argv, 1);
	size = ft_lstsize(stack_a);
	ft_lst_split(&stack_a, &stack_b, size);
	printf("\nReturn List:");
	lst_display(stack_a);
	return (0);
}
