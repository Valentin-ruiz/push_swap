/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 11:04:07 by varuiz            #+#    #+#             */
/*   Updated: 2019/03/25 12:55:01 by varuiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist		*dlist_new(void)
{
	t_dlist	*list;

	if (!(list = (t_dlist *)malloc(sizeof(*list))))
		return (NULL);
	if (list)
	{
		list->len = 0;
		list->tail = NULL;
		list->head = NULL;
	}
	return (list);
}
