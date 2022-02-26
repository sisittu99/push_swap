/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerchi <mcerchi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 14:48:22 by mcerchi           #+#    #+#             */
/*   Updated: 2022/02/26 14:48:25 by mcerchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

void	ft_rrr_or_death(t_list **stack_a, t_list **stack_b, char *str)
{
	if (ft_strcmp(str, "rra\n"))
		ft_rra_check(stack_a);
	else if (ft_strcmp(str, "rrb\n"))
		ft_rrb_check(stack_b);
	else if (ft_strcmp(str, "rrr\n"))
		ft_rrr_check(stack_a, stack_b);
	else
		ft_display_exit();
}

void	ft_exec_sort(t_list **stack_a, t_list **stack_b, char *str)
{
	while (str != NULL)
	{
		if (ft_strcmp(str, "sa\n"))
			ft_sa_check(stack_a);
		else if (ft_strcmp(str, "sb\n"))
			ft_sb_check(stack_b);
		else if (ft_strcmp(str, "ss\n"))
			ft_ss_check(stack_a, stack_b);
		else if (ft_strcmp(str, "pa\n"))
			ft_pa_check(stack_b, stack_a);
		else if (ft_strcmp(str, "pb\n"))
			ft_pb_check(stack_a, stack_b);
		else if (ft_strcmp(str, "ra\n"))
			ft_ra_check(stack_a);
		else if (ft_strcmp(str, "rb\n"))
			ft_rb_check(stack_b);
		else if (ft_strcmp(str, "rr\n"))
			ft_rr_check(stack_a, stack_b);
		else
			ft_rrr_or_death(stack_a, stack_b, str);
		str = ft_get_next_line_gnl(0);
	}
}

void	ft_check_sort(t_list *stack_a)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->content > (stack_a->next)->content)
		{
			write(1, "KO\n", 3);
			return ;
		}
		stack_a = stack_a->next;
	}
	write(1, "OK\n", 3);
	return ;
}

void	ft_check_argv_c(int argc, char **argv, t_list **stack_a)
{
	int		size;
	char	**arg;

	arg = NULL;
	size = 0;
	if (argc == 2)
	{
		arg = ft_split(argv[1], ' ');
		while (arg[size] != NULL)
			size++;
		ft_check_write_lst(stack_a, size, arg, 0);
		free(arg);
	}
	else if (argc >= 3)
		ft_check_write_lst(stack_a, argc, argv, 1);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*str;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	size = 0;
	if (argc < 2)
		return (0);
	else
		ft_check_argv_c(argc, argv, &stack_a);
	str = ft_get_next_line_gnl(0);
	ft_exec_sort(&stack_a, &stack_b, str);
	ft_check_sort(stack_a);
	return (0);
}
