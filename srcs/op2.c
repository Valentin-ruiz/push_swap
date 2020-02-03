/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 23:21:41 by varuiz            #+#    #+#             */
/*   Updated: 2019/04/08 00:36:39 by varuiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			proceed_op(t_ab *pile, int op)
{
	t_op		*tmp;

	if (op >= 0)
	{
		do_op(pile, op);
		store_op(pile, op);
	}
	else
	{
		pile->moves = 0;
		delete_ops(pile->op);
		replace_ops(pile->op);
		tmp = *pile->op;
		while (tmp->prev)
			tmp = tmp->prev;
		while (tmp)
		{
			send_op(tmp->op);
			tmp = tmp->next;
		}
	}
}

void			send_op(int op)
{
	if (op == SA)
		ft_putendl("sa");
	else if (op == SB)
		ft_putendl("sb");
	else if (op == SS)
		ft_putendl("ss");
	else if (op == PA)
		ft_putendl("pa");
	else if (op == PB)
		ft_putendl("pb");
	else if (op == RA)
		ft_putendl("ra");
	else if (op == RB)
		ft_putendl("rb");
	else if (op == RR)
		ft_putendl("rr");
	else if (op == RRA)
		ft_putendl("rra");
	else if (op == RRB)
		ft_putendl("rrb");
	else if (op == RRR)
		ft_putendl("rrr");
}
