/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 04:38:47 by varuiz            #+#    #+#             */
/*   Updated: 2019/03/25 19:33:43 by varuiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_swap_checker_for_a(t_ab *pile)
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
}

static void		ft_swap_checker_for_b(t_ab *pile)
{
	t_value	*tmp;
	t_node	*n;

	tmp = 0;
	n = pile->b->head;
	if (n && n->next)
	{
		tmp = n->v;
		n->v = n->next->v;
		n->next->v = tmp;
	}
	pile->size++;
}

void			ft_swap_checker(t_ab *pile, t_com *com)
{
	if (ft_strcmp("sa", com->action) == 0)
	{
		ft_swap_checker_for_a(pile);
	}
	else if (ft_strcmp("sb", com->action) == 0)
	{
		ft_swap_checker_for_b(pile);
	}
	else if (ft_strcmp("ss", com->action) == 0)
	{
		ft_swap_checker_for_a(pile);
		ft_swap_checker_for_b(pile);
	}
}
