/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligabrie <ligabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:29:01 by ligabrie          #+#    #+#             */
/*   Updated: 2023/07/05 11:53:37 by ligabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*int	check(t_list **lsts)
{
	t_list	*current;

	if (lsts[1])
		return (-1);
	current = lsts[0];
	while (current->next)
	{
		if (current->data > current->next->data)
			return (-1);
		current = current->next;
	}
	return (1);
}*/

void	sort_two(t_list **lsts)
{
	if (lsts[0]->next)
		if (lsts[0]->data > lsts[0]->next->data)
			ra(lsts);
}

int	main(int argc, char *argv[])
{
	t_list	*lsts[2];

	if (argc < 2)
		return (0);
	if (parse_int(argv, lsts))
	{
		if (!is_sorted(lsts))
		{
			if (argc <= 3)
				sort_two(lsts);
			else if (argc == 4)
				sort_three(lsts);
			else
				push_sort(lsts);
		}
	}
	else
		write(1, "Error\n", 6);
	lst_free(lsts);
}
