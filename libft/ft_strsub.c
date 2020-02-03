/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 02:34:09 by varuiz            #+#    #+#             */
/*   Updated: 2018/11/09 17:02:26 by varuiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;

	if (s == NULL)
		return (NULL);
	i = ft_strlen(s);
	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	str = ft_strncpy(str, s + start, len);
	str[len] = '\0';
	return (str);
}
