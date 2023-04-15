/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligabrie <ligabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 09:29:52 by ligabrie          #+#    #+#             */
/*   Updated: 2023/03/31 09:30:18 by ligabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


//final check
int	is_sortet(t_list **lsts)
{
	t_list	*r_head;

	if (lsts[1])
		return(0);
	r_head = lsts[0];
	while (r_head->next)
	{
		if (r_head->data > r_head->next->data)
		{
			return(0);
		}
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
		{
			return(0);
		}
		r_head = r_head->next;
	}
	return (1);
}

t_list	*last (t_list *lst)
{
	t_list	*ret;
	
	ret = lst;
	while (ret->next)
		ret = ret->next;
	return(ret);
}

int	*lst_to_arr(t_list *lst)
{
	int	*tmp;
	t_list	*head;
	int	i;

	i = 1;
	head = lst;
	while (lst->next)
	{
		lst = lst->next;
		i++;
	}
	tmp = (int *)malloc(sizeof(int) * (i + 1));
	if (!tmp)
		return(NULL);
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
			if(arr[i] > arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				sortet = 0;
			}
		}
	}
	return(arr);
}

/*int	*get_pivot(int *arr, int nb_chunks)
{
	int	i;
	int	*piv_map;
	int	arr_len;

	i = 0;
	while (arr[i])
		i++;
	arr_len = i;

	piv_map = (int *)malloc(sizeof(int) * nb_chunks * 2);
	while (i < nb_chunks)
	{
		piv_map[i * 2] = arr[0];
		piv_map[i * 2 + 1] = arr[];

	}

	return(arr);
}*/

int	get_pivot(int *arr, int nb_chunks)
{
	int	len;

	len = 0;//sizeof(arr);
	//printf ("\nentries: ");
	while (arr[len])
	{
		//printf("%d, ", arr[len]);
		len++;
	}
	//printf ("\nlen: %d, pivot: %d\n", len, arr[len/2]);
	return (arr[len/2]);
}

void	push_by_pivot(t_list **lsts, int p)
{
	int	i;
	int	len;

	//printf("\npivot: %d\n", p);
	len = lst_len(lsts[0]);
	i = 0;
	while (i < len)
	{
		if (lsts[0]->data >= p)
			pb(lsts);
		else
		{
			ra (lsts);
			//lsts[0] = rotate(lsts[0]);
		}
		i++;
		//lst_log(lsts);
	}
}

void	b_sort(t_list **lsts, int lowest)
{
	//lowest must be last
	t_list	*head;

	head = lsts[1];
	while (!is_rev_sortet(lsts[1]))
	{
		//printf("-");
	}
}


t_list	**sort(t_list **lsts)
{
	int	nb_chunks;
	int	*arr;

	arr = lst_to_arr(lsts[0]);
	arr = arr_sort(arr);

	push_by_pivot(lsts, get_pivot(arr, 1));
	return(lsts);
}
