/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligabrie <ligabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:01:44 by ligabrie          #+#    #+#             */
/*   Updated: 2023/07/04 13:20:43 by ligabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cases(t_list **lsts, int c)
{
	if (c == 0)
	{
		ra(lsts);
		sa(lsts);
		rra(lsts);
	}
	else if (c == 1)
		sa(lsts);
	else if (c == 2)
		rra(lsts);
	else if (c == 3)
		ra (lsts);
	else if (c == 4)
	{
		sa(lsts);
		rra(lsts);
	}
}

void	sort_three(t_list **lsts)
{
	int	nbs[3];

	if (lst_len(lsts[0]) == 3)
	{
		nbs[0] = lsts[0]->data;
		nbs[1] = lsts[0]->next->data;
		nbs[2] = lsts[0]->next->next->data;
	}
	if (nbs[0] < nbs[1] && nbs[1] < nbs[2])
		return ;
	if (nbs[0] > nbs[1])
	{
		if (nbs[1] > nbs[2])
			cases(lsts, 4);
		else if (nbs[0] > nbs[2])
			cases(lsts, 3);
		else
			cases(lsts, 1);
	}
	else if (nbs[0] > nbs[2])
		cases(lsts, 2);
	else
		cases(lsts, 0);
}
