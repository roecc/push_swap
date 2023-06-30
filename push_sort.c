/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligabrie <ligabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:33:22 by ligabrie          #+#    #+#             */
/*   Updated: 2023/06/30 14:53:38 by ligabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sortet(t_list **lsts)
{
	t_list	*r_head;

	if (lsts[1])
		return (0);
	r_head = lsts[0];
	while (r_head->next)
	{
		if (r_head->data > r_head->next->data)
			return (0);
		r_head = r_head->next;
	}
	return (1);
}

int	is_rev_sortet(t_list *lst)
{
	t_list	*r_head;

	if (!lst)
		return (0);
	r_head = lst;
	while (r_head->next)
	{
		if (r_head->data < r_head->next->data)
			return (0);
		r_head = r_head->next;
	}
	return (1);
}

t_list	*last(t_list *lst)
{
	t_list	*ret;

	ret = lst;
	while (ret->next)
		ret = ret->next;
	return (ret);
}

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

int	*get_pivots(int *arr, int nc, int *pivots)
{
	int	len;
	int	p1;

	len = 0;
	while (arr[len])
		len++;
	p1 = (len / nc) * (nc - 1);
	pivots[0] = arr[p1 - (len / nc / 2)];
	pivots[1] = arr[p1];
	return (pivots);
}

void	push_by_pivot(t_list **lsts, int *p)
{
	int	i;
	int	len;
	int	tmp;

	len = lst_len(lsts[0]);
	i = 0;
	while (i < len)
	{
		tmp = lsts[0]->data;
		if (tmp <= p[1])
		{
			pb(lsts);
			if (tmp <= p[0])
			{
				if (lsts[0]->data > p[1])
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

void	rev_push_by_pivot(t_list **lsts, int *p)
{
	int	i;
	int	len;
	int	tmp;

	len = lst_len(lsts[0]);
	i = 0;
	while (i < len)
	{
		tmp = lsts[0]->data;
		if (tmp <= p[1])
		{
			pb(lsts);
			if (tmp > p[0])
			{
				if (lsts[0]->data > p[1])
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

void	walk_to_red(t_list **lsts, int p)
{
	t_list	*head;
	int		found;

	found = 0;
	head = lsts[1];
	while (head->next)
	{
		head = head->next;
		if (head->data <= p)
			found = 1;
		else if (found)
			break ;
	}
	while (lsts[1] != head)
		rrb (lsts);
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

t_list	**sort(t_list **lsts)
{
	int	*arr;
	int	piv[2];
	int	p_line;
	int	i;

	arr = lst_to_arr(lsts[0]);
	arr = arr_sort(arr);
	get_pivots(arr, 2, piv);
	p_line = piv[1];	
	push_by_pivot(lsts, piv);
	i = 2;
	while (i <= 128)
	{
		i = i * 2;
		get_pivots(arr, i, piv);
		rev_push_by_pivot(lsts, piv);
		walk_to_red (lsts, p_line);
	}
	return_sort(arr, lsts);
	free(arr);
	return(lsts);
}
