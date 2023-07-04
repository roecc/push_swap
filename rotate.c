/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligabrie <ligabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:06:36 by ligabrie          #+#    #+#             */
/*   Updated: 2023/07/04 13:16:36 by ligabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*rotate(t_list *lst)
{
	t_list	*old_first;
	t_list	*old_last;

	if (!lst)
		return (lst);
	old_first = lst;
	old_last = lst;
	while (old_last->next)
		old_last = old_last->next;
	old_last->next = old_first;
	lst = old_first->next;
	old_first->next = NULL;
	return (lst);
}

void	ra(t_list *lsts[])
{
	lsts[0] = rotate(lsts[0]);
	write (1, "ra\n", 3);
}

void	rb(t_list *lsts[])
{
	lsts[1] = rotate(lsts[1]);
	write (1, "rb\n", 3);
}

void	rr(t_list *lsts[])
{
	lsts[0] = rotate(lsts[0]);
	lsts[1] = rotate(lsts[1]);
	write (1, "rr\n", 3);
}
