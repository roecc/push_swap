/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligabrie <ligabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:40:33 by ligabrie          #+#    #+#             */
/*   Updated: 2023/07/05 09:43:36 by ligabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_next(int n, t_list **lsts)
{
	t_list	*current;
	int		i;
	int		found;
	int		blen;

	i = 0;
	found = 0;
	current = lsts[1];
	blen = lst_len(lsts[1]);
	while (current->next && i < ((blen - i) / 2))
	{
		if (current->data == n)
			found = 1;
		current = current->next;
		i++;
	}
	while (lsts[1]->data != n)
	{
		if (found)
			rb(lsts);
		else
			rrb(lsts);
	}
	pa(lsts);
}

void	return_sort(int	*arr, t_list **lsts)
{
	int	bound;

	bound = 30000;
	while (lsts[0])
		pb(lsts);
	while (lsts[1] && bound-- > 0)
		find_next(arr[lst_len(lsts[1]) - 1], lsts);
}

void	recu(int *arr, int n, int len, t_list **lsts)
{
	int	mid;
	int	mid_mid;

	mid = arr[(len / n) * (n - 1)];
	mid_mid = arr[(len / n) * (n - 1) - (len / n / 2)];
	if (n == 2)
		push_by_pivot(lsts, mid, mid_mid);
	else
		rev_push_by_pivot(lsts, mid, mid_mid);
	if ((len / n / 2) >= 4)
		recu(arr, n * 2, len, lsts);
}

void	push_sort(t_list **lsts)
{
	int	*arr;
	int	len;

	len = lst_len(lsts[0]);
	arr = lst_to_arr(lsts[0]);
	arr = arr_sort(arr);
	if (len == 5)
	{
		sort_five(lsts, arr);
		return ;
	}
	recu(arr, 2, len, lsts);
	return_sort(arr, lsts);
	free (arr);
}
