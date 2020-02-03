/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_rev_checker.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 04:38:47 by varuiz            #+#    #+#             */
/*   Updated: 2019/04/02 23:18:09 by varuiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_rotate_rev_checker_for_a(t_ab *pile)
{
	t_node	*last;

	last = pile->a->tail;
	if (last && (last->prev || last->next))
	{
		pile->a->tail = last->prev;
		pile->a->tail->next = NULL;
		last->prev = NULL;
		last->next = pile->a->head;
		pile->a->head->prev = last;
		pile->a->head = last;
	}
	pile->size++;
}

static void		ft_rotate_rev_checker_for_b(t_ab *pile)
{
	t_node	*last;

	last = pile->b->tail;
	if (last && (last->prev || last->next))
	{
		pile->b->tail = last->prev;
		pile->b->tail->next = NULL;
		last->prev = NULL;
		last->next = pile->b->head;
		pile->b->head->prev = last;
		pile->b->head = last;
	}
	pile->size++;
}

void			ft_rotate_rev_checker(t_ab *pile, t_com *com)
{
	if (ft_strcmp("rra", com->action) == 0)
	{
		ft_rotate_rev_checker_for_a(pile);
	}
	else if (ft_strcmp("rrb", com->action) == 0)
	{
		ft_rotate_rev_checker_for_b(pile);
	}
	else if (ft_strcmp("rrr", com->action) == 0)
	{
		ft_rotate_rev_checker_for_a(pile);
		ft_rotate_rev_checker_for_b(pile);
	}
}
