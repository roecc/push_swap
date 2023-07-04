/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligabrie <ligabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:05:00 by ligabrie          #+#    #+#             */
/*   Updated: 2023/07/04 13:17:20 by ligabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to(t_list *lsts[], char c)
{
	int		to;
	int		from;
	t_list	*a_new_first;

	to = c - 'a';
	from = 1 - to;
	if (lsts[from])
	{
		a_new_first = lsts[from]->next;
		lsts[from]->next = lsts[to];
		lsts[to] = lsts[from];
		lsts[from] = a_new_first;
	}
}

void	pa(t_list *lsts[])
{
	push_to(lsts, 'a');
	write(1, "pa\n", 3);
}

void	pb(t_list *lsts[])
{
	push_to(lsts, 'b');
	write(1, "pb\n", 3);
}
