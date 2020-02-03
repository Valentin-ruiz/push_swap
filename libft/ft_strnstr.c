/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 23:19:17 by varuiz            #+#    #+#             */
/*   Updated: 2018/11/08 07:17:02 by varuiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *dest, size_t len)
{
	size_t		i;
	size_t		y;
	const char	*l;
	const char	*s;

	i = 0;
	if (*dest == '\0')
		return ((char *)src);
	while (*src != '\0' && i < len)
	{
		l = src;
		s = dest;
		y = i;
		while (*s != '\0' && *l == *s && y < len)
		{
			l++;
			s++;
			y++;
		}
		if (*s == '\0')
			return ((char *)src);
		src++;
		i++;
	}
	return (NULL);
}
