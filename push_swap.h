/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligabrie <ligabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:29:12 by ligabrie          #+#    #+#             */
/*   Updated: 2023/07/05 09:39:42 by ligabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

t_list	*parse_int(char **av);
t_list	*lst_new(int data);
void	lst_free(t_list *lsts[]);
int		lst_len(t_list *lst);
void	sort_three(t_list **lsts);
void	sort_five(t_list **lsts, int *arr);

void	sa(t_list *lsts[]);
void	sb(t_list *lsts[]);
void	ss(t_list *lsts[]);

void	pa(t_list *lsts[]);
void	pb(t_list *lsts[]);

void	ra(t_list *lsts[]);
void	rb(t_list *lsts[]);
void	rr(t_list *lsts[]);

void	rra(t_list *lsts[]);
void	rrb(t_list *lsts[]);
void	rrr(t_list *lsts[]);

void	push_sort(t_list **lsts);

int		*lst_to_arr(t_list *lst);
int		*arr_sort(int *arr);

void	push_by_pivot(t_list **lsts, int mid, int mid_mid);
void	rev_push_by_pivot(t_list **lsts, int mid, int mid_mid);

#endif