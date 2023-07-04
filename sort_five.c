/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligabrie <ligabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:23:31 by ligabrie          #+#    #+#             */
/*   Updated: 2023/07/04 13:41:17 by ligabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_five(t_list **lsts)
{
	int	arr[5];
	int	i;
	t_list	*current;

	i = 0;
	current = lsts[0];
	while (current)
	{
		arr[i] = current->data;
		i++;
		current = current->next;
	}
}
