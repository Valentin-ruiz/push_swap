/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 22:49:24 by varuiz            #+#    #+#             */
/*   Updated: 2019/04/18 15:17:47 by varuiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		check_med(t_ab *pile, int *st, int a)
{
	if (a)
	{
		if (pile->is_med && next_target(st, pile->dist, pile->med, 1)
			!= INT_MAX && (pile->med_pushed = 1) && pile->len_b > 1)
			proceed_op(pile, RB);
		else if (pile->is_med && next_target(st, pile->dist, pile->med, 2)
			== INT_MIN)
			pile->med_pushed = 1;
		else if (pile->med_pushed && next_target(st, pile->dist, pile->med, 1)
			== INT_MAX)
			proceed_op(pile, RRB);
	}
	else
	{
		if (pile->is_med && next_target(st, pile->dist, pile->med, 3)
			!= INT_MIN && (pile->med_pushed = 1) && pile->len_a > 1)
			proceed_op(pile, RA);
		else if (pile->is_med && next_target(st, pile->dist, pile->med, 2)
			== INT_MIN)
			pile->med_pushed = 1;
		else if (pile->med_pushed && next_target(st, pile->dist, pile->med, 3)
			== INT_MIN)
			proceed_op(pile, RRA);
	}
}

void			split_b(t_ab *pile, int *st)
{
	int			op;
	int			back_in_order;

	pile->med_pushed = 0;
	back_in_order = 1;
	while (!pile->med_pushed || next_target(st, pile->dist, pile->med, 3)
		!= INT_MIN)
	{
		pile->is_med = 0;
		if (st[0] > pile->med || (st[0] == pile->med
			&& (pile->is_med = 1)))
		{
			pile->dist--;
			op = PA;
		}
		else
		{
			back_in_order++;
			op = RB;
		}
		proceed_op(pile, op);
		check_med(pile, pile->stack_b, 0);
	}
	while (--back_in_order && !is_sorted(st, pile->len_b, 0, 0))
		proceed_op(pile, RRB);
}

void			split_a(t_ab *pile, int *st)
{
	int			op;
	int			back;

	pile->med_pushed = 0;
	back = 1;
	while (!pile->med_pushed || next_target(st, pile->dist, pile->med, 1)
		!= INT_MAX)
	{
		pile->is_med = 0;
		if (st[0] < pile->med || (st[0] == pile->med
			&& (pile->is_med = 1)))
		{
			pile->dist--;
			op = PB;
		}
		else
		{
			back++;
			op = RA;
		}
		proceed_op(pile, op);
		check_med(pile, pile->stack_a, 1);
	}
	while (pile->first_round && --back && !is_sorted(st, pile->len_a, 0, 1))
		proceed_op(pile, RRA);
}
