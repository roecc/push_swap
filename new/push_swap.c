/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligabrie <ligabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:38:03 by ligabrie          #+#    #+#             */
/*   Updated: 2023/06/30 15:50:51 by ligabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*lsts[2];

	lsts[0] = parse_int(argv);
	lsts[1] = NULL;
	
	sort_three(lsts);
	lst_free(lsts);
	return (0);
}
