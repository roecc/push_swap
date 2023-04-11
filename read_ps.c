/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligabrie <ligabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:42:05 by ligabrie          #+#    #+#             */
/*   Updated: 2023/03/29 18:52:51 by ligabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	**parse_ps (char *inst, t_list *lsts[])
{
	int	i;
	int	nw;

	nw = 1;
	i = 0;
	while (inst[i])
	{

		if (inst[i] == ' ')
		{
			printf("\n");
			lst_log(lsts);
		}
		else
		{
			if (inst[i] == 's')
			{
				i++;
				if (inst[i] == 'a')
					swap(lsts[0]);
				else if (inst[i] == 'b')
					swap(lsts[1]);
				else if (inst[i] == 's')
				{
					swap(lsts[0]);
					swap(lsts[1]);
				}
			}
			else if (inst[i] == 'p')
			{
				i++;
				if (inst[i] == 'a')
					pa(lsts);
				else if (inst[i] == 'b')
					pb(lsts);
			}
			else if (inst[i] == 'r')
			{
				i++;
				if (inst[i] == 'a')
					lsts[0] = rotate(lsts[0]);
				else if (inst[i] == 'b')
					lsts[1] = rotate(lsts[1]);
				else if (inst[i] == 'r')
				{
					i++;
					if (inst[i] == ' ' || inst[i] == '\0')
					{
						lsts[0] = rotate(lsts[0]);
						lsts[1] = rotate(lsts[1]);
					}
					else if (inst[i] == 'a')
						lsts[0] = rev_rotate(lsts[0]);
					else if (inst[i] == 'b')
						lsts[1] = rev_rotate(lsts[1]);
					else if (inst[i] == 'r')
					{
						lsts[0] = rev_rotate(lsts[0]);
						lsts[1] = rev_rotate(lsts[1]);
					}
				}
			}
			//else
				//printf("not found");
			nw = 0;
		}
		i++;
	}
	printf("\n");
	lst_log(lsts);

	return (lsts);
}