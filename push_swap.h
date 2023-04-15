/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligabrie <ligabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:53:20 by ligabrie          #+#    #+#             */
/*   Updated: 2023/04/15 11:57:07 by ligabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	int			data;
	struct s_list	*next;
}					t_list;

/*typedef struct s_block
{
	int	low;
	int	high;
}*/

int		ft_atoi(const char *str);
t_list	*ft_lstnew(int data);
void	lst_free(t_list *lsts[]);
void	lst_log(t_list *lsts[]);
int		lst_len (t_list *lst);

t_list	*swap (t_list *lst);
void	pb (t_list *lsts[]);
void	pa (t_list *lsts[]);
t_list	*rotate(t_list *lst);
t_list	*rev_rotate(t_list *lst);
void	push_to (t_list *lsts[], char c);

t_list	*parse_int (char **av);
t_list	**parse_ps (char *inst, t_list *lsts[]);

t_list	**sort(t_list **lsts);
int		is_sortet(t_list **lsts);

void	fake_sort(t_list *lst);

void	sa (t_list *lsts[]);
void	sb (t_list *lsts[]);
void	ss (t_list *lsts[]);
void	ra (t_list *lsts[]);
void	rb (t_list *lsts[]);
void	rr (t_list *lsts[]);
void	rra (t_list *lsts[]);
void	rrb (t_list *lsts[]);
void	rrr (t_list *lsts[]);
