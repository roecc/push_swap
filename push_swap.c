/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligabrie <ligabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:29:01 by ligabrie          #+#    #+#             */
/*   Updated: 2023/07/05 09:47:17 by ligabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check(t_list **lsts)
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
}

int	main(int argc, char *argv[])
{
	t_list	*lsts[2];

	if (argc < 3)
		write(1, "error\n", 6);
	lsts[0] = parse_int(argv);
	lsts[1] = NULL;
	if (argc == 4)
		sort_three(lsts);
	else
		push_sort(lsts);
	if (check(lsts) == -1)
		write (1, "\nKO\n", 4);
	else
		write (1, "\nOK!\n", 4);
}
