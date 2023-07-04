/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligabrie <ligabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:40:33 by ligabrie          #+#    #+#             */
/*   Updated: 2023/07/04 17:54:55 by ligabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*lst_to_arr(t_list *lst)
{
	int		*tmp;
	t_list	*head;
	int		i;

	i = 1;
	head = lst;
	while (lst->next)
	{
		lst = lst->next;
		i++;
	}
	tmp = (int *)malloc(sizeof(int) * (i + 1));
	if (!tmp)
		return (NULL);
	lst = head;
	i = 0;
	while (lst->next)
	{
		tmp[i] = lst->data;
		lst = lst->next;
		i++;
	}
	tmp[i] = lst->data;
	tmp[i + 1] = '\0';
	return (tmp);
}

int	*arr_sort(int *arr)
{
	int	i;
	int	sortet;
	int	tmp;

	sortet = 0;
	while (!sortet)
	{
		sortet = 1;
		i = -1;
		while (arr[++i + 1])
		{
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				sortet = 0;
			}
		}
	}
	return (arr);
}

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
			//> for switch
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

int	find_next(int n, t_list **lsts)
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
		{
			found = 1;
			break;
		}
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
	return (i);
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
	int	mid; //1
	int	mid_mid; //0

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
	//sort_three(lsts);
	return_sort(arr, lsts);
	free (arr);
}
