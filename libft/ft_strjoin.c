/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 02:41:40 by varuiz            #+#    #+#             */
/*   Updated: 2018/11/09 21:08:19 by varuiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	int		ii;
	size_t	y;

	i = 0;
	ii = 0;
	if (s1 == '\0' || s2 == '\0')
		return (NULL);
	y = ft_strlen(s1) + ft_strlen(s2);
	str = ft_strnew(y + 1);
	if (str == NULL)
		return (NULL);
	while (i < y)
	{
		if (i < ft_strlen(s1))
			str[i] = s1[i];
		else
			str[i] = s2[ii++];
		i++;
	}
	str[i] = '\0';
	return (str);
}
