/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 23:21:41 by varuiz            #+#    #+#             */
/*   Updated: 2019/05/13 17:49:49 by varuiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			is_not_ranked(t_ab *pile, int *st, int len)
{
	int		i;
	int		count;
	int		rank;

	i = -1;
	count = 0;
	rank = -1;
	while (++i + 1 < len)
	{
		if (count == 0 && st[i] > st[i + 1])
		{
			rank = i;
			count++;
			i++;
		}
		if (i + 1 < len && count > 0
			&& (st[i] > st[i + 1]
			|| (st[i] < st[i - 1]
			&& (st[i] != pile->min || st[i - 1] != pile->max))))
			return (-1);
	}
	return (rank);
}

int			is_sorted(int *st, int len, int start, int inc)
{
	int		i;

	i = start - 1;
	if (inc)
	{
		while (++i + 1 < len)
		{
			if (st[i] >= st[i + 1])
				return (0);
		}
	}
	else
	{
		while (++i + 1 < len)
		{
			if (st[i] <= st[i + 1])
			{
				return (0);
			}
		}
	}
	return (1);
}
