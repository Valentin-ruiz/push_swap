/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 23:19:05 by varuiz            #+#    #+#             */
/*   Updated: 2019/07/30 15:42:07 by varuiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pile_sa(t_ab *pile, int print)
{
	t_value	*tmp;
	t_node	*n;

	tmp = 0;
	n = pile->a->head;
	if (n && n->next)
	{
		tmp = n->v;
		n->v = n->next->v;
		n->next->v = tmp;
	}
	pile->size++;
	if (print == 1)
		store_op(pile, SA);
}

void	ft_pile_ra(t_ab *pile, int print)
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
	if (print == 1)
		store_op(pile, RA);
}

void	ft_pile_rra(t_ab *pile, int print)
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
	if (print == 1)
		store_op(pile, RRA);
}

void	ft_pile_rrra(t_ab *pile, int print)
{
	ft_pile_rra(pile, print);
	ft_pile_rra(pile, print);
}

void	ft_pile_pa(t_ab *pile, int print)
{
	if (pile->b->head)
	{
		dlist_push_front(pile->a, pile->b->head->v->nbr,
			pile->b->head->v->index);
		pile->b = dlist_remove_head(pile->b);
	}
	pile->size++;
	if (print == 1)
		store_op(pile, PA);
}
