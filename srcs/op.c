/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 23:21:41 by varuiz            #+#    #+#             */
/*   Updated: 2019/07/30 14:19:28 by varuiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		reverse_rotate(int *st, int len)
{
	int			i;
	int			j;

	if (len > 1)
	{
		i = st[len - 1];
		j = len;
		while (--j > 0)
			st[j] = st[j - 1];
		st[j] = i;
	}
}

static void		rotate(int *st, int len)
{
	int			i;
	int			j;

	if (len > 1)
	{
		i = st[0];
		j = -1;
		while (++j + 1 < len)
			st[j] = st[j + 1];
		st[j] = i;
	}
}

static void		push(int *st1, int *st2, int *len1, int *len2)
{
	int			i;
	int			j;

	if (*len2 > 0)
	{
		i = st2[0];
		j = -1;
		while (++j + 1 < *len2)
			st2[j] = st2[j + 1];
		*len2 -= 1;
		j = *len1 + 1;
		while (--j > 0)
			st1[j] = st1[j - 1];
		st1[0] = i;
		*len1 += 1;
	}
}

static void		swap(int *tab, int len)
{
	int			i;

	if (len > 1)
	{
		i = tab[0];
		tab[0] = tab[1];
		tab[1] = i;
	}
}

void			do_op(t_ab *pile, int op)
{
	if (op == SA || op == SS)
		swap(pile->stack_a, pile->len_a);
	if (op == SB || op == SS)
		swap(pile->stack_b, pile->len_b);
	else if (op == PA)
		push(pile->stack_a, pile->stack_b, &pile->len_a, &pile->len_b);
	else if (op == PB)
		push(pile->stack_b, pile->stack_a, &pile->len_b, &pile->len_a);
	else if (op == RA || op == RR)
		rotate(pile->stack_a, pile->len_a);
	if (op == RB || op == RR)
		rotate(pile->stack_b, pile->len_b);
	else if (op == RRA || op == RRR)
		reverse_rotate(pile->stack_a, pile->len_a);
	if (op == RRB || op == RRR)
		reverse_rotate(pile->stack_b, pile->len_b);
}
