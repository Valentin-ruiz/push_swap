/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 22:27:10 by varuiz            #+#    #+#             */
/*   Updated: 2018/11/08 07:17:37 by varuiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *src, const char *dest)
{
	const char *l;
	const char *s;

	if (*dest == '\0')
		return ((char *)src);
	while (*src != '\0')
	{
		l = src;
		s = dest;
		while (*s != '\0' && *l == *s)
		{
			l++;
			s++;
		}
		if (*s == '\0')
			return ((char *)src);
		src++;
	}
	return (NULL);
}
