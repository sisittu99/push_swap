/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:53:52 by mcerchi           #+#    #+#             */
/*   Updated: 2022/02/20 13:02:05 by fdrudi           ###   ########.fr       */
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

void	ft_move_to_b(t_list **stack_a, t_list **stack_b, int start, int end)
{
	int	i;
	int	size;
	int	count;

	size = ft_lstsize(*stack_a);
	// printf("\nMove To B List:\n");
	// lst_display(*stack_a);
	// printf("\nStart: %d\t End: %d\n", start, end);
	i = ft_choose_best_nbr_a(*stack_a, size, start, end);
	while (i != size + 1)
	{
	//	printf("\nIndicatore Mosse A: %d\n", i);
		if (i < 0)
			while (i++ <= 0)
				ft_rra(stack_a);
		else if (i > 0 && i < size)

			while (i-- > 0)
				ft_ra(stack_a);
		ft_pb(stack_a, stack_b);
		i = ft_choose_best_nbr_a(*stack_a, size, start, end);
	}
	// printf("\nIndicatore Mosse A: %d\n", i);
	// printf("\nSize: %d\n", size);
	// printf("\nPost Move To B List:\n");
	// lst_display(*stack_a);
	// printf("\nB ListPost Move To B List:\n");
	// lst_display(*stack_b);
	while (*stack_b != NULL)
	{
		count = 0;
		i = ft_choose_best_nbr_b(*stack_b, ft_lstsize(*stack_b));
		//printf("\nIndicatore Mosse B: %d\n", i);
		if (i < 0)
			while (i++ < 0)
				ft_rrb(stack_b);
		else if (i > 0)
			while (i-- > 0)
				ft_rb(stack_b);
		while ((*stack_a)->content < (*stack_b)->content)
		{
			ft_ra(stack_a);
			count++;
		}
		ft_pa(stack_b, stack_a);
		while (count-- > 0)
			ft_rra(stack_a);
	}

}

void	ft_sort_three(t_list **stack_a)
{
	int	i;
	int	j;
	int	x;
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
	int	n;

	n = 0;
	//printf("\nsplit size : %d\n", size);
	if (size == 3)
	{
		ft_sort_three(stack_a);
		return ;
	}
	// while (size / n > 26)
	// 	n++;
	dst = ft_copy_cont(*stack_a, size);

	arr = longestSubSeq(dst, size);
	/*while (i <= size)
	{
		arr[i] = 1;
		while (n < i)
		{
			if (dst[i] > dst[n] && arr[i] < arr[n] + 1)
				arr[i] = arr[n] + 1;
			n++;
		}
		n = 0;
		i++;
	}*/
	n = 0;
	while (n < 9)
	{
		printf("%d ", arr[n]);
		n++;
	}
	exit (0);

	// //printf("\nDest Copy: ");
	// i = -1;
	// while (i++ < size)
	// 	printf("%d ", dst[i]);
	// i = 0;
	// printf("\nSplit lista:\n");
	// lst_display(*stack_a);
	// dst = quicksort(dst, 0, size);
	// size = (size / n);
	// i = 0;
	// while (i < n)
	// {
		ft_move_to_b(stack_a, stack_b, dst[size * i], dst[size * (i + 1)]);
	// 	i++;
	// }
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
