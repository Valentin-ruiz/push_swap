/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 23:21:41 by varuiz            #+#    #+#             */
/*   Updated: 2019/04/04 18:11:49 by varuiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		new_link(t_op **op, t_op *new)
{
	new->prev = *op;
	(*op)->next = new;
	*op = new;
}

void			store_op(t_ab *pile, int op)
{
	t_op		*new;

	if (!(new = (t_op*)ft_memalloc(sizeof(t_op))))
		exit(ft_end(4));
	new->op = op;
	new->i = pile->moves;
	if (*pile->op)
		new_link(pile->op, new);
	else
		*pile->op = new;
}
