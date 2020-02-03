/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 04:40:04 by varuiz            #+#    #+#             */
/*   Updated: 2018/11/08 07:53:47 by varuiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		neg;
	int		len;
	int		tmp;
	char	*str;

	tmp = n;
	len = 2;
	while (tmp /= 10)
		len++;
	neg = (n < 0) ? 1 : 0;
	n *= (n < 0) ? -1 : 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len += neg;
	if ((str = (char *)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	while (len-- > 0)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (neg == 1)
		str[0] = '-';
	return (str);
}
