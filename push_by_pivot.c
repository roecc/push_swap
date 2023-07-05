/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_by_pivot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligabrie <ligabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 09:38:47 by ligabrie          #+#    #+#             */
/*   Updated: 2023/07/05 09:40:11 by ligabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_by_pivot(t_list **lsts, int mid, int mid_mid)
{
	int	i;
	int	tmp;
	int	len;

	i = 0;
	len = lst_len(lsts[0]);
	while (i < len)
	{
		tmp = lsts[0]->data;
		if (tmp <= mid)
		{
			pb(lsts);
			if (tmp <= mid_mid)
			{
				if (lsts[0]->data > mid)
					rr (lsts);
				else
					rb (lsts);
			}
		}
		else
			ra (lsts);
		i++;
	}
}

void	rev_push_by_pivot(t_list **lsts, int mid, int mid_mid)
{
	int	i;
	int	tmp;
	int	len;

	i = 0;
	len = lst_len(lsts[0]);
	while (i < len)
	{
		tmp = lsts[0]->data;
		if (tmp <= mid)
		{
			pb(lsts);
			if (tmp > mid_mid)
			{
				if (lsts[0]->data > mid)
					rr (lsts);
				else
					rb (lsts);
			}
		}
		else
			ra (lsts);
		i++;
	}
}
