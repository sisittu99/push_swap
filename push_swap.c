/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:53:52 by mcerchi           #+#    #+#             */
/*   Updated: 2022/02/13 18:28:10 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./libft/libft.h"

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

void	ft_lstposition(t_list **stack_a, t_list **stack_b, const int size)
{
	t_list	*pos_a;
	t_list	*pos_b;
	int		i;

	i = -1;
	pos_a = NULL;
	while (++i < size)
	{
		pos_a = ft_lstnew(0);

	}
}

int	main(int argc, char **argv)
{
	t_list			*stack_a;
	t_list			*stack_b;
	const int		size;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 3)
		ft_display_exit();
	ft_write_lst(&stack_a, argc, argv);
	size = ft_lstsize(stack_a);
	//creo una lista dove mi segno la posizione che il numero dovrebbe avere.
	ft_lstposition(&stack_a, &stack_b, size);
	lst_display(stack_a);
	return (0);
}
