/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 11:03:42 by varuiz            #+#    #+#             */
/*   Updated: 2019/04/03 08:51:53 by varuiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				ft_end(int status)
{
	if (status == 0 || status == 10)
	{
		if (status == 0)
			ft_putendl("OK");
		return (0);
	}
	if (status == 1)
		ft_putendl_fd("Error", 2);
	else if (status == 2)
	{
		ft_putendl("KO");
		return (0);
	}
	else if (status == 3)
		ft_putendl_fd("Error (read)", 2);
	else if (status == 4)
		ft_putendl_fd("Error (malloc)", 2);
	return (-1);
}
