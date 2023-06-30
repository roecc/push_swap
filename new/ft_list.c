/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligabrie <ligabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 23:13:13 by admin             #+#    #+#             */
/*   Updated: 2023/06/30 15:04:05 by ligabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_list	*ft_lstnew(int data)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (lst == NULL)
		return (NULL);
	lst->data = data;
	lst->next = NULL;
	return (lst);
}

void	lst_free(t_list *lsts[])
{
	t_list *tmp;
	while (lsts[0])
	{
		tmp = lsts[0];
		lsts[0] = lsts[0]->next;
		free (tmp);
	}
	while (lsts[1])
	{
		tmp = lsts[1];
		lsts[1] = lsts[1]->next;
		free (tmp);
	}
}

int	lst_len (t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
