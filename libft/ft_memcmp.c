/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 20:34:47 by varuiz            #+#    #+#             */
/*   Updated: 2018/11/08 07:07:19 by varuiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *x;
	unsigned char *y;

	x = (unsigned char *)s1;
	y = (unsigned char *)s2;
	while (n > 0 && *x == *y)
	{
		x++;
		y++;
		n--;
	}
	if (n == 0)
		return (0);
	else
		return (*x - *y);
}
