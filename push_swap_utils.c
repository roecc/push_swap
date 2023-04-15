/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:22:06 by ligabrie          #+#    #+#             */
/*   Updated: 2023/04/15 14:57:33 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa (t_list *lsts[])
{
	lsts[0] = swap (lsts[0]);
	write (1, "sa\n", 3);
}

void	sb (t_list *lsts[])
{
	lsts[1] = swap (lsts[1]);
	write (1, "sb\n", 3);
}

void	ss (t_list *lsts[])
{
	lsts[0] = swap (lsts[0]);
	lsts[1] = swap (lsts[1]);
	write (1, "ss\n", 3);
}

t_list	*swap (t_list *lst)
{
	int	tmp;
	
	if (lst && lst->next)
	{
		tmp = lst->data;
		lst->data = lst->next->data;
		lst->next->data = tmp;
	}
	return (lst);
}

//push
void	pa (t_list *lsts[])
{
	push_to(lsts, 'a');
	write(1, "pa\n", 3);
}

void	pb (t_list *lsts[])
{
	push_to(lsts, 'b');
	write(1, "pb\n", 3);
}

/*void	pa (t_list *lsts[])
{
	t_list	*a_new_first;

	if (lsts[1])
	{
		a_new_first = lsts[1]->next;
		lsts[1]->next = lsts[0];
		lsts[0] = lsts[1];
		lsts[1] = a_new_first;
	}
}*/

void	push_to (t_list *lsts[], char c)
{
	int	to;
	int from;
	t_list	*a_new_first;

	to = c - 'a';
	from = 1 - to;
	if (lsts[from])
	{
		a_new_first = lsts[from]->next;
		lsts[from]->next = lsts[to];
		lsts[to] = lsts[from];
		lsts[from] = a_new_first;
	}
}

void	ra (t_list *lsts[])
{
	lsts[0] = rotate(lsts[0]);
	write (1, "ra\n", 3);
}

void	rb (t_list *lsts[])
{
	lsts[1] = rotate(lsts[1]);
	write (1, "rb\n", 3);
}

void	rr (t_list *lsts[])
{
	lsts[0] = rotate(lsts[0]);
	lsts[1] = rotate(lsts[1]);
	write (1, "rr\n", 3);
}
//might cause issue with single stacks
t_list	*rotate(t_list *lst)
{
	t_list	*old_first;
	t_list	*old_last;

	if (!lst)
		return (lst);
	old_first = lst;
	old_last = lst;
	while (old_last->next)
		old_last = old_last->next;
	old_last->next = old_first;
	lst = old_first->next;
	old_first->next = NULL;
	return (lst);
}

void	rra (t_list *lsts[])
{
	lsts[0] = rev_rotate(lsts[0]);
	write (1, "rra\n", 4);
}

void	rrb (t_list *lsts[])
{
	lsts[1] = rev_rotate(lsts[1]);
	write (1, "rrb\n", 4);
}

void	rrr (t_list *lsts[])
{
	lsts[0] = rev_rotate(lsts[0]);
	lsts[1] = rev_rotate(lsts[1]);
	write (1, "rrr\n", 4);
}

t_list	*rev_rotate(t_list *lst)
{
	t_list	*old_first;
	t_list	*old_last;

	if (!lst)
		return (lst);
	old_first = lst;
	old_last = lst;
	if (old_last->next)
	{
		while (old_last->next->next)
			old_last = old_last->next;
		lst = old_last->next;
		old_last->next->next = old_first;
		old_last->next = NULL;
	}
	return (lst);
}

/*
t_list	*parse_int (char *s)
{
	int	i;
	int	nn;
	t_list	*lst;
	t_list	*curr;

	lst = ft_lstnew(ft_atoi(s));
	curr = lst;
	nn = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] == ' ')
			nn = 1;
		//if (s[i] >= '0' && s[i] <= '9' && nn)
		if (nn)
		{
			nn = 0;
			curr->next = ft_lstnew(ft_atoi(s + i));
			curr = curr->next;
		}
	}
	return (lst);
}
*/

t_list	*parse_int (char **av)
{
	int	i;
	int	nn;
	t_list	*lst;
	t_list	*curr;

	lst = ft_lstnew(ft_atoi(av[1]));
	curr = lst;
	nn = 0;
	i = 1;
	while (av[++i])
	{
		nn = 0;
		curr->next = ft_lstnew(ft_atoi(av[i]));
		curr = curr->next;
	}
	return (lst);
}
