/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligabrie <ligabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 09:36:08 by ligabrie          #+#    #+#             */
/*   Updated: 2023/07/05 12:40:32 by ligabrie         ###   ########.fr       */
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

int	*arr_sort(int *arr, int len)
{
	int	i;
	int	sortet;
	int	tmp;

	sortet = 0;
	while (!sortet)
	{
		sortet = 1;
		i = -1;
		while (++i + 1 < len)
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
