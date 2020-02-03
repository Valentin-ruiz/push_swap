/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 04:38:47 by varuiz            #+#    #+#             */
/*   Updated: 2019/04/02 23:43:20 by varuiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_rotate_checker_for_a(t_ab *pile)
{
	t_node	*first;

	first = pile->a->head;
	if (first && (first->prev || first->next))
	{
		pile->a->head = first->next;
		pile->a->head->prev = NULL;
		first->next = NULL;
		first->prev = pile->a->tail;
		pile->a->tail->next = first;
		pile->a->tail = first;
	}
	pile->size++;
}

static void		ft_rotate_checker_for_b(t_ab *pile)
{
	t_node	*first;

	first = pile->b->head;
	if (first && (first->prev || first->next))
	{
		pile->b->head = first->next;
		pile->b->head->prev = NULL;
		first->next = NULL;
		first->prev = pile->b->tail;
		pile->b->tail->next = first;
		pile->b->tail = first;
	}
	pile->size++;
}

void			ft_rotate_checker(t_ab *pile, t_com *com)
{
	if (ft_strcmp("ra", com->action) == 0)
	{
		ft_rotate_checker_for_a(pile);
	}
	else if (ft_strcmp("rb", com->action) == 0)
	{
		ft_rotate_checker_for_b(pile);
	}
	else if (ft_strcmp("rr", com->action) == 0)
	{
		ft_rotate_checker_for_a(pile);
		ft_rotate_checker_for_b(pile);
	}
}
