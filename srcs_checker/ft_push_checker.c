/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 04:38:47 by varuiz            #+#    #+#             */
/*   Updated: 2019/04/23 13:00:43 by varuiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_push_checker_for_a(t_ab *pile)
{
	if (pile->b->head)
	{
		dlist_push_front(pile->a, pile->b->head->v->nbr,
			pile->b->head->v->index);
		pile->b = dlist_remove_head(pile->b);
	}
	pile->size++;
}

static void		ft_push_checker_for_b(t_ab *pile)
{
	if (pile->a->head)
	{
		dlist_push_front(pile->b, pile->a->head->v->nbr,
			pile->a->head->v->index);
		pile->a = dlist_remove_head(pile->a);
	}
	pile->size++;
}

void			ft_push_checker(t_ab *pile, t_com *com)
{
	if (ft_strcmp("pa", com->action) == 0)
	{
		ft_push_checker_for_a(pile);
	}
	else if (ft_strcmp("pb", com->action) == 0)
	{
		ft_push_checker_for_b(pile);
	}
}
