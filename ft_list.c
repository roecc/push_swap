/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligabrie <ligabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 23:13:13 by admin             #+#    #+#             */
/*   Updated: 2023/03/31 14:15:43 by ligabrie         ###   ########.fr       */
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

void	lst_log(t_list *lsts[])
{
	t_list	*ca;
	t_list	*cb;

	ca = lsts[0];
	cb = lsts[1];
	while (ca && cb)
	{
		printf("%d\t%d\n", ca->data, cb->data);
		cb = cb->next;
		ca = ca->next;
	}
	while (ca)
	{
		printf("%d\n", ca->data);
		ca = ca->next;
	}
	while (cb)
	{
		printf("\t%d\n", cb->data);
		cb = cb->next;
	}
	printf("\n");
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