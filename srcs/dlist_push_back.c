/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_push_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 11:03:52 by varuiz            #+#    #+#             */
/*   Updated: 2019/03/25 19:32:11 by varuiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist		*dlist_push_back(t_dlist *list, int nbr, int index)
{
	t_node	*n;
	t_value	*v;

	n = (t_node*)malloc(sizeof(*n));
	if (n)
	{
		n->v = (t_value*)malloc(sizeof(*v));
		n->v->nbr = nbr;
		n->v->index = index;
		n->next = NULL;
		if (!list->tail)
		{
			n->prev = NULL;
			list->tail = n;
			list->head = n;
		}
		else
		{
			list->tail->next = n;
			n->prev = list->tail;
			list->tail = n;
		}
		list->len++;
	}
	return (list);
}
