/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligabrie <ligabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:23:59 by ligabrie          #+#    #+#             */
/*   Updated: 2023/07/05 11:24:20 by ligabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
In case of error, it must display "Error" followed by a ’\n’ on the standard error.
Errors include for example: some arguments aren’t integers, some arguments are
bigger than an integer and/or there are duplicates.

Run push_swap with non numeric parameters.

Run push_swap with a duplicate numeric parameter.

Run push_swap with only numeric parameters including one greater
than MAXINT.

Run push_swap without any parameters. ->not display anything and give the prompt back
*/

#include "push_swap.h"

//int	check_duplicates()
