/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 23:21:41 by varuiz            #+#    #+#             */
/*   Updated: 2019/05/14 23:08:34 by varuiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_is_sort(t_dlist *a)
{
	t_node	*n;

	if (a)
	{
		n = a->head;
		if (n == NULL)
			return (0);
		while (n->next)
		{
			if (n->v->nbr > n->next->v->nbr)
				return (0);
			n = n->next;
		}
		return (1);
	}
	return (0);
}

int		ft_is_empty(t_dlist *b)
{
	t_node	*n;

	n = b->head;
	if (n->next)
	{
		return (0);
	}
	return (1);
}
