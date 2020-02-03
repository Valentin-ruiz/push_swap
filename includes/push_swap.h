/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 04:38:47 by varuiz            #+#    #+#             */
/*   Updated: 2019/10/07 18:28:36 by varuiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdio.h>

typedef struct		s_value
{
	int				nbr;
	int				index;
}					t_value;

typedef struct		s_node
{
	t_value			*v;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct		s_dlist
{
	int				len;
	t_node			*tail;
	t_node			*head;
}					t_dlist;

typedef	struct s_op	t_op;

struct				s_op
{
	enum {
		SA,
		SB,
		SS,
		PA,
		PB,
		RA,
		RB,
		RR,
		RRA,
		RRB,
		RRR
	}				op;
	int				i;
	t_op			*prev;
	t_op			*next;
};

typedef struct		s_ab
{
	t_dlist			*a;
	t_dlist			*b;
	int				*stack_a;
	int				*stack_b;
	long			size;
	int				print;
	int				min;
	int				*tab_med;
	int				tab_med_i;
	int				len_a;
	int				len_b;
	int				med;
	int				is_med;
	int				med_pushed;
	int				dist;
	int				max;
	char			first_round;
	int				nb_elem;
	t_op			**op;
	int				moves;
}					t_ab;

typedef struct		s_nbr
{
	unsigned int	small;
	unsigned int	big;
	unsigned int	lastbig;
	unsigned int	len;
}					t_nbr;

typedef struct		s_base
{
	unsigned int	a;
	unsigned int	ni;
}					t_base;

typedef	struct		s_com
{
	char			*action;
	struct s_com	*next;
}					t_com;

typedef struct		s_rm
{
	t_op			*tmp;
	t_op			*tmp2;
	int				doit;
}					t_rm;

t_node				*dlist_create_node(t_value *value);
t_dlist				*dlist_new(void);
t_dlist				*dlist_push_back(t_dlist *list, int nbr, int index);
t_dlist				*dlist_push_front(t_dlist *list, int nbr, int index);
t_dlist				*dlist_remove_head(t_dlist *list);
t_dlist				*dlist_remove_tail(t_dlist *list);
void				tab_free(t_ab **ablst, int argc, char **argv, int len);
void				tdlist_free(t_node **alst);
void				tcom_free(t_com **comlst);

int					ft_sort(t_dlist *a);
int					ft_swap(t_ab *pile, t_node *n, int way);
void				ft_algo(t_ab *pile);

void				ft_swap_sa(t_ab	*pile, t_node *n, int way);
void				ft_check_sa(t_ab *pile);
void				ft_swap_simple(t_node *bot, t_node *top);
void				ft_cocktail_simple(t_dlist *b);

void				ft_print_error();
int					ft_no_double(t_node *lst, int nbr);
int					ft_is_number(char *data);
int					ft_is_valid(char *argv);
void				ft_print_pile(t_dlist *lst);
int					ft_is_sort(t_dlist *a);
void				ft_pile_sa(t_ab *pile, int print);
void				ft_pile_sb(t_ab *pile, int print);
void				ft_pile_ss(t_ab *pile);
void				ft_pile_pa(t_ab *pile, int print);
void				ft_pile_pb(t_ab *pile, int print);
void				ft_pile_ra(t_ab *pile, int print);
void				ft_pile_rb(t_ab *pile, int print);
void				ft_pile_rr(t_ab *pile);
void				ft_pile_rra(t_ab *pile, int print);
void				ft_pile_rrb(t_ab *pile, int print);
void				ft_pile_rrr(t_ab *pile);

void				ft_reset(t_dlist *b, t_dlist *a);
void				ft_clear_pile(t_dlist *b);
void				ft_prepare(t_ab	*pile, int nb_elem);

t_ab				*ft_init_pile(void);
void				ft_resolve(t_ab *pile, int nb_elem);

void				ft_getcom(t_com **com);
char				*ft_checkcom(char *str);
void				ft_execute(t_ab *pile, t_com *com);
void				ft_swap_checker(t_ab *pile, t_com *com);
void				ft_push_checker(t_ab *pile, t_com *com);
void				ft_rotate_checker(t_ab *pile, t_com *com);
void				ft_rotate_rev_checker(t_ab *pile, t_com *com);

int					is_sorted(int *st, int len, int start, int inc);
void				quick_sort(t_ab *pile);
int					get_dist_to_med(int *st, int size, int next_med);
int					get_next_med(t_ab *pile, int *st, int size);
int					get_max(int *st, int len);
int					get_min(int *st, int len);
int					get_med(int *st, int len);
void				split_a(t_ab *pile, int *st);
void				split_b(t_ab *pile, int *st);
void				replace_ops(t_op **op);
void				delete_ops(t_op **op);
void				proceed_op(t_ab *pile, int op);
void				do_op(t_ab *pile, int op);
void				store_op(t_ab *pile, int op);
void				send_op(int op);
int					ft_end(int status);
int					next_target(int *st, int len, int target, char comp);
void				sort_a(t_ab *pile);
int					is_not_ranked(t_ab *pile, int *st, int len);
void				shift_a(t_ab *pile, int len, int rank, int pb);
void				top_free(t_op **oplst);
int					ft_is_empty(t_dlist *a);
void				ft_pile_rrra(t_ab *pile, int print);
#endif
