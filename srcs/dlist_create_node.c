/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 11:03:42 by varuiz            #+#    #+#             */
/*   Updated: 2019/03/15 04:02:27 by varuiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node		*dlist_create_node(t_value *value)
{
	t_node	*n;

	n = (t_node*)malloc(sizeof(t_node));
	if (n)
	{
		n->v = value;
		n->prev = NULL;
		n->next = NULL;
	}
	return (n);
}
