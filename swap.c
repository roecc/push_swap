/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligabrie <ligabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:03:00 by ligabrie          #+#    #+#             */
/*   Updated: 2023/07/04 13:19:09 by ligabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*swap(t_list *lst)
{
	int	tmp;

	if (lst && lst->next)
	{
		tmp = lst->data;
		lst->data = lst->next->data;
		lst->next->data = tmp;
	}
	return (lst);
}

void	sa(t_list *lsts[])
{
	lsts[0] = swap (lsts[0]);
	write (1, "sa\n", 3);
}

void	sb(t_list *lsts[])
{
	lsts[1] = swap (lsts[1]);
	write (1, "sb\n", 3);
}

void	ss(t_list *lsts[])
{
	lsts[0] = swap (lsts[0]);
	lsts[1] = swap (lsts[1]);
	write (1, "ss\n", 3);
}
