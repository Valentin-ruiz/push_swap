/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 23:21:41 by varuiz            #+#    #+#             */
/*   Updated: 2019/06/25 11:25:57 by varuiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		add_med(int **tab_med, int size, int val)
{
	int			i;
	int			*tab;

	tab = *tab_med;
	i = 0;
	while (i < size)
	{
		if (tab[i] == INT_MIN)
		{
			tab[i] = val;
			return ;
		}
		i++;
	}
}

static void		check_b(t_ab *p)
{
	while (is_sorted(p->stack_a, p->len_a, 0, 1)
		&& !is_sorted(p->stack_b, p->len_b, 0, 0))
	{
		if (p->len_b > 1 && p->stack_b[1] == get_max(p->stack_b, p->len_b))
			proceed_op(p, SB);
		if (is_sorted(p->stack_b, p->len_b, 0, 0))
			break ;
		p->med = get_next_med(p, p->stack_b, p->len_b);
		p->dist = get_dist_to_med(p->stack_b, p->len_b, p->med);
		if (p->med != INT_MIN && p->dist > 2
			&& !is_sorted(p->stack_b, p->dist, 0, 2))
		{
			add_med(&p->tab_med, p->nb_elem, get_med(p->stack_b, p->dist));
			p->med = get_next_med(p, p->stack_b, p->dist);
			p->tab_med_i++;
		}
		else if (p->med == INT_MIN)
		{
			add_med(&p->tab_med, p->nb_elem, get_med(p->stack_b, p->len_b));
			p->med = p->tab_med[p->tab_med_i];
			p->dist = p->len_b;
			p->tab_med_i++;
		}
		split_b(p, p->stack_b);
	}
}

static void		check_a(t_ab *p)
{
	while (!is_sorted(p->stack_a, p->len_a, 0, 1))
	{
		if (p->len_a > 1 && p->stack_a[1] == get_min(p->stack_a, p->len_a))
			proceed_op(p, SA);
		if (is_sorted(p->stack_a, p->len_a, 0, 1))
			break ;
		p->med = get_next_med(p, p->stack_a, p->len_a);
		p->dist = get_dist_to_med(p->stack_a, p->len_a, p->med);
		if (p->med != INT_MIN && p->dist > 2
			&& !is_sorted(p->stack_a, p->dist, 0, 1))
		{
			add_med(&p->tab_med, p->nb_elem, get_med(p->stack_a, p->dist));
			p->med = get_next_med(p, p->stack_a, p->dist);
			p->tab_med_i++;
		}
		else if (p->med == INT_MIN)
		{
			add_med(&p->tab_med, p->nb_elem, get_med(p->stack_a, p->len_a));
			p->med = p->tab_med[p->tab_med_i];
			p->dist = p->len_a;
			p->tab_med_i++;
		}
		split_a(p, p->stack_a);
	}
}

void			quick_sort(t_ab *pile)
{
	int			i;

	i = -1;
	while (++i < pile->nb_elem)
		pile->tab_med[i] = INT_MIN;
	pile->tab_med_i = 0;
	pile->first_round = 0;
	while (!is_sorted(pile->stack_a, pile->len_a, 0, 1)
		|| !is_sorted(pile->stack_b, pile->len_b, 0, 0))
	{
		check_a(pile);
		pile->first_round = 1;
		check_b(pile);
	}
	while (pile->len_b)
		proceed_op(pile, PA);
}
