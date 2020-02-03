/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 23:21:41 by varuiz            #+#    #+#             */
/*   Updated: 2019/04/04 18:11:56 by varuiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				next_target(int *st, int len, int target, char comp)
{
	int			i;

	i = -1;
	if (comp == 1)
	{
		while (++i < len)
			if (st[i] < target)
				return (i);
	}
	else if (comp == 2)
	{
		while (++i < len)
			if (st[i] == target)
				return (i);
	}
	else if (comp == 3)
	{
		while (++i < len)
			if (st[i] > target)
				return (i);
	}
	return (comp == 1 ? INT_MAX : INT_MIN);
}
