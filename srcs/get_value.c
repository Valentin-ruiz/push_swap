/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 22:49:24 by varuiz            #+#    #+#             */
/*   Updated: 2019/04/06 18:34:20 by varuiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				get_dist_to_med(int *st, int size, int next_med)
{
	int			i;

	i = 0;
	while (i < size && st[i] != next_med)
		i++;
	if (i == size)
		return (0);
	return (i);
}

int				get_next_med(t_ab *pile, int *st, int size)
{
	int			i;
	int			j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < pile->nb_elem && pile->tab_med[j] != INT_MIN)
		{
			if (st[i] == pile->tab_med[j])
				return (pile->tab_med[j]);
			j++;
		}
		i++;
	}
	return (INT_MIN);
}

int				get_max(int *st, int len)
{
	int			i;
	int			j;
	int			max;

	max = INT_MIN;
	i = -1;
	while (++i < len)
	{
		j = -1;
		while (++j < len)
		{
			if (st[j] > max)
				max = st[j];
		}
	}
	return (max);
}

int				get_min(int *st, int len)
{
	int			i;
	int			j;
	int			min;

	min = INT_MAX;
	i = -1;
	while (++i < len)
	{
		j = -1;
		while (++j < len)
		{
			if (st[j] < min)
				min = st[j];
		}
	}
	return (min);
}

int				get_med(int *st, int len)
{
	int			i;
	int			j;
	int			dist;
	int			med;

	i = -1;
	med = INT_MIN;
	while (++i < len)
	{
		dist = 0;
		j = -1;
		while (++j < len)
		{
			if (st[j] > st[i])
				dist++;
		}
		if (dist == (len % 2 == 0 ? (len / 2) - 1 : len / 2))
		{
			med = st[i];
			break ;
		}
	}
	return (med);
}
