/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:47:06 by mcerchi           #+#    #+#             */
/*   Updated: 2022/02/24 15:42:53 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

void	ft_write_lst(t_list **stack_a, int argc, char **argv, int i);
void	ft_move_to_b(t_list **stack_a, t_list **stack_b, int *arr, int max);
void	ft_move_to_a(t_list **stack_a, t_list **stack_b);
void	ft_lst_split(t_list **stack_a, t_list **stack_b, int size);
void	ft_lstcheck(t_list *stack_a, int check);
void	ft_lst_order(t_list **stack_a);
void	ft_sa(t_list **stack_a);
void	ft_sb(t_list **stack_b);
void	ft_ss(t_list **stack_a, t_list **stack_b);
void	ft_pa(t_list **stack_b, t_list **stack_a);
void	ft_pb(t_list **stack_a, t_list **stack_b);
void	ft_ra(t_list **stack_a);
void	ft_rb(t_list **stack_b);
void	ft_rr(t_list **stack_a, t_list **stack_b);
void	ft_rra(t_list **stack_a);
void	ft_rrb(t_list **stack_b);
void	ft_rrr(t_list **stack_a, t_list **stack_b);
int		*ft_copy_cont(t_list *stack_a, int size);
int		ft_min_nbr(int a, int b);
int		ft_the_needed(int min, int max, int size);
int		ft_best_nbr_b(t_list **stack_b, int size_b,
			t_list **stack_a, int size_a);
int		ft_best_nbr_a(t_list *stack_a, int size, int *arr, int max);
void	ft_check_argv(int argc, char *argv, t_list **stack_a);
int		*ft_define_lis(int *dst, int size, int *max);
int		*ft_long_lis(int *dst, int *arr, int size, int *ret);
int		ft_the_needed_b(int max, int size);
int		ft_the_needed_a(t_list *stack_a, int cont, int size);
int		ft_max_nbr(int a, int b);
int		ft_best_comb(int *arr_a, int *arr_b, int size);
int		ft_move_a(int a, int b, t_list **stack_a, t_list **stack_b);
int		ft_max_or_min(t_list *stack_a, int cont, int size);
int		return_max_or_min(int cont, int *max_n_min, int size);
int		*ft_intcpy(int	*arr, int size);
void	ft_search_min(t_list **stack_a, int size);
void	ft_sort_three(t_list **stack_a);
int		*ft_lis_util(int *dst, int *arr, int max, int size);
void	ft_sort_five(t_list **stack_a, t_list **stack_b);

void	lst_display(t_list *stack_a);

#endif
