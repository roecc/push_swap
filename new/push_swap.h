/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligabrie <ligabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:00:44 by ligabrie          #+#    #+#             */
/*   Updated: 2023/06/30 15:51:12 by ligabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<unistd.h>

typedef struct s_list
{
	int			data;
	struct s_list	*next;
}					t_list;

int		ft_atoi(const char *str);
t_list	*parse_int (char **av);
t_list	*ft_lstnew(int data);
t_list	*swap (t_list *lst);
t_list	*rotate(t_list *lst);
t_list	*rev_rotate(t_list *lst);
void	push_to (t_list *lsts[], char c);
void	lst_free(t_list *lsts[]);
void	lst_log(t_list *lsts[]);
int		lst_len (t_list *lst);
void	pb (t_list *lsts[]);
void	pa (t_list *lsts[]);
void	sa (t_list *lsts[]);
void	sb (t_list *lsts[]);
void	ss (t_list *lsts[]);
void	ra (t_list *lsts[]);
void	rb (t_list *lsts[]);
void	rr (t_list *lsts[]);
void	rra (t_list *lsts[]);
void	rrb (t_list *lsts[]);
void	rrr (t_list *lsts[]);

void	sort_three(t_list **lsts);

