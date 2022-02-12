/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerchi <mcerchi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:18:25 by mcerchi           #+#    #+#             */
/*   Updated: 2022/02/12 16:27:13 by mcerchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sa(int *stack_a)
{
	int tmp;

	tmp = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = tmp;
	write(1, "sa\n", 3);
}

void	ft_sb(int *stack_b)
{
	int	tmp;

	tmp = stack_b[0];
	stack_b[0] = stack_b[1];
	stack_b[1] = tmp;
	write(1, "sa\n", 3);
}

void	ft_ss(int *stack_a, int *stack_b)
{
	ft_sa(stack_a);
	ft_sb(stack_b);
}

void	ft_pa(int *stack_a, int *stack_b)
{
	int	tmp;
	int	len;

	len = 0;
	while (stack_a[len] != NULL)
		len++;
	tmp = stack_a[len - 1];
	if (!stack_b)
		return ;
	stack_a[len + 1] = NULL;
	while (len > 0)
	{
		stack_a[len--] = tmp;
		tmp = stack_a[len - 1];
	}
	stack_a[0] = stack_b[0];
	while (stack_b[len] != NULL)
	{
		stack_b
	}
	write(1, "pa\n", 3);
}

void	*ft_pb(int *stack_a, int *stack_b)
{
	tmp
	write(1, "pb\n", 3);
}

