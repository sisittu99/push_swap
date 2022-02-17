/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerchi <mcerchi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:53:52 by mcerchi           #+#    #+#             */
/*   Updated: 2022/02/17 12:36:32 by mcerchi          ###   ########.fr       */
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

void	ft_lst_split(t_list **stack_a, t_list **stack_b, int size)
{
	int	*dst;
	int	i;

	i = 0;
	dst = ft_copy_cont(stack_a, size);

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
	size = ft_lstsize(stack_a);
	//creo una lista dove mi segno la posizione che il numero dovrebbe avere.
	ft_lst_split(&stack_a, &stack_b, size);
	lst_display(stack_a);
	return (0);
}
