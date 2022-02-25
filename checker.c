/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:30:28 by fdrudi            #+#    #+#             */
/*   Updated: 2022/02/25 19:25:37 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**arg;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	arg = NULL;
	size = 0;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		arg = ft_split(argv[1], ' ');
		while (arg[size] != NULL)
			size++;
		ft_write_lst(&stack_a, size, arg, 0);
		free(arg);
	}
	else if (argc >= 3)
		ft_write_lst(&stack_a, argc, argv, 1);
}
