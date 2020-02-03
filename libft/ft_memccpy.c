/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 20:03:28 by varuiz            #+#    #+#             */
/*   Updated: 2018/11/08 07:21:45 by varuiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned int		i;
	unsigned char		*x;
	unsigned char		*y;

	i = 0;
	x = (unsigned char *)src;
	y = (unsigned char *)dest;
	while (i < n)
	{
		y[i] = x[i];
		if (x[i] == (unsigned char)c)
		{
			return ((void *)&y[i + 1]);
		}
		i++;
	}
	return (NULL);
}
