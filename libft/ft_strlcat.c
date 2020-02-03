/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 21:25:46 by varuiz            #+#    #+#             */
/*   Updated: 2018/11/08 07:14:07 by varuiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	char			*d;
	const char		*s;
	size_t			len;
	size_t			dlen;

	d = dest;
	s = src;
	len = size;
	while (len-- != '\0' && *d != '\0')
		d++;
	dlen = d - dest;
	len = size - dlen;
	if (len == 0)
		return (dlen + ft_strlen(s));
	while (*s != '\0')
	{
		if (len != 1)
		{
			*d++ = *s;
			len--;
		}
		s++;
	}
	*d = '\0';
	return (dlen + (s - src));
}
