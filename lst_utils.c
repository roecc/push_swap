/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligabrie <ligabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:38:47 by ligabrie          #+#    #+#             */
/*   Updated: 2023/07/04 13:20:05 by ligabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lst_new(int data)
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
	t_list	*tmp;

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

int	lst_len(t_list *lst)
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
