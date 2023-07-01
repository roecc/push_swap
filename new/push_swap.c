/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligabrie <ligabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:38:03 by ligabrie          #+#    #+#             */
/*   Updated: 2023/07/01 14:34:02 by ligabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*lsts[2];

	if (argc > 3)
		write(1, "error\n", 6);
	

	lsts[0] = parse_int(argv);
	lsts[1] = NULL;
	
	sort_three(lsts);
	//ft_lstclear(lsts[0]);
	//ft_lstclear(lsts[1]);
	lst_free(lsts);
	return (0);
}
