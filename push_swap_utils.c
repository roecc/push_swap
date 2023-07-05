/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligabrie <ligabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:48:50 by ligabrie          #+#    #+#             */
/*   Updated: 2023/07/05 12:20:24 by ligabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*t_list	*parse_int(char **av)
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
}*/

int	parse_int(char **av, t_list **lsts)
{
	int			i;
	t_list		*curr;
	long int	val;

	val = ft_atoi(av[1]);
	lsts[0] = lst_new(val);
	lsts[1] = NULL;
	curr = lsts[0];
	if (val > 2147483647 || val < -2147483648)
		return (0);
	i = 1;
	while (av[++i])
	{
		val = ft_atoi(av[i]);
		curr->next = lst_new(val);
		curr = lsts[0];
		while (curr->next)
		{
			if (curr->data == val || val > 2147483647 || val < -2147483648)
				return (0);
			curr = curr->next;
		}
	}
	return (1);
}

int	is_sorted(t_list **lsts)
{
	t_list	*current;

	if (lsts[1])
		return (0);
	current = lsts[0];
	while (current->next)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}
