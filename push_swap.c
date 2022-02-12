/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerchi <mcerchi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:53:52 by mcerchi           #+#    #+#             */
/*   Updated: 2022/02/12 16:27:11 by mcerchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

t_list	*write_lst(int argc, char **argv)
{
	t_list	*tmp;
	t_list	*tmp2;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	tmp = NULL;
	while (i < argc)
	{
		tmp2 = ft_lstnew(ft_atoi(argv[i + 1]));
		if (tmp != NULL)
			tmp->next = tmp2;
		while (j++ < i)
		{
			if (tmp2->content == tmp)
			{
				ft_display_exit();
			}
		}
		tmp = tmp2;
		j = 0;
		i++;
	}
	while (arr[j] < arr[j + 1] && j + 2 < i)
	{
		if (arr[j + 1] > arr[j + 2])
			return (arr);
		j++;
	}
	ft_display_exit();
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	**stack_b;

	if (argc < 3)
		ft_display_exit();
	stack_a = write_lst(argc, argv);
	stack_b = ft_lstnew(0);
	return(0);
}
