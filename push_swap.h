/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:47:06 by mcerchi           #+#    #+#             */
/*   Updated: 2022/02/18 15:06:02 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

void	ft_write_lst(t_list **stack_a, int argc, char **argv, int i);
void	ft_move_to_b(t_list **stack_a, t_list **stack_b, int start, int end);
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
int		*quicksort(int *number,int first,int last);
void	swap(int *a, int *b);
int		*ft_copy_cont(t_list *stack_a, int size);
int		ft_min_nbr(int a, int b);
int		ft_the_needed(int min, int max, int size);
int		ft_choose_best_nbr_b(t_list *stack_b, int size);
int		ft_choose_best_nbr_a(t_list *stack_a, int size, int sep_one, int sep_two);
void	ft_check_argv(int argc, char *argv, t_list **stack_a);


void	lst_display(t_list *stack_a);

#endif
