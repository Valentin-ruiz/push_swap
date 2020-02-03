/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 22:49:24 by varuiz            #+#    #+#             */
/*   Updated: 2019/05/13 19:12:12 by varuiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_sort(t_dlist *a)
{
	t_node	*n;

	n = a->head;
	while (n->next)
	{
		if (n->v->index > n->next->v->index)
			return (0);
		n = n->next;
	}
	return (1);
}

int		ft_swap(t_ab *pile, t_node *n, int way)
{
	int		ret;

	ret = 0;
	if (pile->a->head->v->index - 1 == pile->a->head->next->v->index)
		ft_pile_sa(pile, 1);
	else if (pile->a->tail->v->index - 1 == pile->a->head->v->index)
		ft_pile_rra(pile, 1);
	else if (pile->a->head->v->index == pile->min && ++ret && !ft_sort(pile->a))
	{
		ft_pile_pb(pile, 1);
		pile->min++;
	}
	else if (n->v->index != pile->a->head->v->index)
	{
		while (n->v->index != pile->a->head->v->index)
		{
			if (way)
				ft_pile_ra(pile, 1);
			else
				ft_pile_rra(pile, 1);
		}
	}
	if (ft_sort(pile->a))
		return (1);
	return (ret);
}

void	ft_algo(t_ab *pile)
{
	int		swap;
	int		way;
	t_node	*n;
	int		pos;

	swap = 1;
	n = pile->a->head;
	while (swap)
	{
		swap = 0;
		pos = 0;
		way = 1;
		n = pile->a->head;
		while (n && n->next && n->v->index != pile->min && ++pos)
			n = n->next;
		if (!ft_sort(pile->a))
		{
			if (pos > pile->a->len / 2)
				way = 0;
			while (!swap)
				swap = ft_swap(pile, n, way);
		}
	}
	while (pile->b && pile->b->head)
		ft_pile_pa(pile, 1);
}
