/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligabrie <ligabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:48:50 by ligabrie          #+#    #+#             */
/*   Updated: 2023/07/04 13:16:54 by ligabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*parse_int(char **av)
{
	int		i;
	t_list	*lst;
	t_list	*curr;

	lst = lst_new(ft_atoi(av[1]));
	curr = lst;
	i = 1;
	while (av[++i])
	{
		curr->next = lst_new(ft_atoi(av[i]));
		curr = curr->next;
	}
	return (lst);
}
