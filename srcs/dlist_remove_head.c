/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_remove_head.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 11:04:18 by varuiz            #+#    #+#             */
/*   Updated: 2019/03/15 04:02:47 by varuiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist		*dlist_remove_head(t_dlist *list)
{
	t_node	*first;
	t_node	*new_first;

	first = list->head;
	new_first = first->next;
	first->prev = NULL;
	first->next = NULL;
	if (new_first)
	{
		new_first->prev = NULL;
		list->head = new_first;
	}
	else
	{
		list->tail = NULL;
		list->head = NULL;
	}
	free(first->v);
	first->v = NULL;
	free(first);
	first = NULL;
	if (list->len)
		list->len--;
	return (list);
}
