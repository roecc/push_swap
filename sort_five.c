/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligabrie <ligabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:23:31 by ligabrie          #+#    #+#             */
/*   Updated: 2023/07/04 17:50:50 by ligabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_five(t_list **lsts, int *arr)
{
	while (lst_len(lsts[0]) > 3)
	{
		if (lsts[0]->data == arr[0] || lsts[0]->data == arr[1])
			pb(lsts);
		else
			ra(lsts);
	}
	sort_three(lsts);
	if (lsts[1]->data < lsts[1]->next->data)
		sb(lsts);
	pa(lsts);
	pa(lsts);
}
