/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligabrie <ligabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:07:37 by ligabrie          #+#    #+#             */
/*   Updated: 2023/07/04 13:20:57 by ligabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*rev_rotate(t_list *lst)
{
	t_list	*old_first;
	t_list	*old_last;

	if (!lst)
		return (lst);
	old_first = lst;
	old_last = lst;
	if (old_last->next)
	{
		while (old_last->next->next)
			old_last = old_last->next;
		lst = old_last->next;
		old_last->next->next = old_first;
		old_last->next = NULL;
	}
	return (lst);
}

void	rra(t_list *lsts[])
{
	lsts[0] = rev_rotate(lsts[0]);
	write (1, "rra\n", 4);
}

void	rrb(t_list *lsts[])
{
	lsts[1] = rev_rotate(lsts[1]);
	write (1, "rrb\n", 4);
}

void	rrr(t_list *lsts[])
{
	lsts[0] = rev_rotate(lsts[0]);
	lsts[1] = rev_rotate(lsts[1]);
	write (1, "rrr\n", 4);
}
