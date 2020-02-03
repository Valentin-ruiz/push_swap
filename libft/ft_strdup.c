/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 20:39:59 by varuiz            #+#    #+#             */
/*   Updated: 2018/11/08 07:10:38 by varuiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		y;
	char	*d;

	i = ft_strlen(s);
	y = 0;
	d = (char *)malloc((i + 1) * sizeof(char));
	if (d == NULL)
		return (NULL);
	while (y < i)
	{
		d[y] = s[y];
		y++;
	}
	d[y] = '\0';
	return (d);
}
