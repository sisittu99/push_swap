/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerchi <mcerchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:53:52 by mcerchi           #+#    #+#             */
/*   Updated: 2022/02/12 13:23:41 by mcerchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

int	*write_array(int argc, char **argv)
{
	int		*arr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	arr = (int *) malloc (sizeof(int) * argc);
	if (!arr)
		ft_display_exit();
	while (i < argc)
	{
		arr[i] = ft_atoi(argv[i + 1]);
		while (j++ < i)
		{
			if (arr[j] == arr[i])
			{
				free(arr);
				ft_display_exit();
			}
		}
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
	int	*stack_a;
	int	*stack_b;

	if (argc < 3)
		ft_display_exit();
	stack_a = write_array(argc, argv);
	stack_b = (int *) malloc (sizeof(int) * argc);
	if (!stack_b)
	{
		free(stack_a);
		ft_display_exit();
	}

}
