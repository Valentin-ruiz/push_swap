/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:56:55 by varuiz            #+#    #+#             */
/*   Updated: 2018/11/07 20:01:08 by varuiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *x;
	unsigned char *y;

	x = (unsigned char *)src;
	y = (unsigned char *)dest;
	while (n > 0)
	{
		*y = *x;
		y++;
		x++;
		n--;
	}
	return (dest);
}
