/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 02:59:04 by varuiz            #+#    #+#             */
/*   Updated: 2018/11/28 17:07:28 by varuiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		x;
	int		y;
	char	*str;

	i = 0;
	x = 0;
	if (s == NULL)
		return (NULL);
	y = ft_strlen(s) - 1;
	while (s[x] == ' ' || s[x] == '\n' || s[x] == '\t')
		x++;
	while ((s[y] == ' ' || s[y] == '\n' || s[y] == '\t') && x <= y)
		y--;
	if (!(str = ft_memalloc(y - x + 1)))
		return (NULL);
	while (x <= y)
	{
		str[i] = s[x];
		x++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
