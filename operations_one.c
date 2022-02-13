/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:18:25 by mcerchi           #+#    #+#             */
/*   Updated: 2022/02/13 10:46:28 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sa(t_list **stack_a)
{
	int		i;
	t_list	*tmp;

	tmp = *stack_a;
	i = 0;
	tmp = tmp->next;
	i = tmp->content;
	tmp->content = (*stack_a)->content;
	(*stack_a)->content = i;
	write(1, "sa\n", 3);
	return ;
}

void	ft_sb(t_list **stack_b)
{
	int		i;
	t_list	*tmp;

	tmp = *stack_b;
	i = 0;
	tmp = tmp->next;
	i = tmp->content;
	tmp->content = (*stack_b)->content;
	(*stack_b)->content = i;
	write(1, "sb\n", 3);
	return ;
}

void	ft_ss(t_list **stack_a, t_list **stack_b)
{
	int		i;
	t_list	*tmp;

	tmp = *stack_a;
	i = 0;
	tmp = tmp->next;
	i = tmp->content;
	tmp->content = (*stack_a)->content;
	(*stack_a)->content = i;
	tmp = *stack_b;
	i = 0;
	tmp = tmp->next;
	i = tmp->content;
	tmp->content = (*stack_b)->content;
	(*stack_b)->content = i;
	write(1, "ss\n", 3);
	return ;
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

