/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_ab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 23:19:19 by varuiz            #+#    #+#             */
/*   Updated: 2019/04/08 00:48:35 by varuiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pile_ss(t_ab *pile)
{
	ft_pile_sa(pile, 0);
	ft_pile_sb(pile, 0);
	store_op(pile, SS);
}

void	ft_pile_rr(t_ab *pile)
{
	ft_pile_ra(pile, 0);
	ft_pile_rb(pile, 0);
	store_op(pile, RR);
}

void	ft_pile_rrr(t_ab *pile)
{
	ft_pile_rra(pile, 0);
	ft_pile_rrb(pile, 0);
	pile->size++;
	store_op(pile, RRR);
}
