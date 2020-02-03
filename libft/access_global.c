/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_global.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:56:15 by valentin          #+#    #+#             */
/*   Updated: 2019/03/15 04:15:29 by varuiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**format_getptr(void)
{
	static char	*ptr;

	*ptr = NULL;
	return (&ptr);
}

char		*format_get(void)
{
	return (*(format_getptr()));
}

void		format_set(char *format)
{
	char	**ptr;

	ptr = format_getptr();
	*ptr = format;
}

char		*format_get_pos_ptr(int pos)
{
	return (format_get() + pos);
}

char		format_get_pos(int pos)
{
	return (*(format_get() + pos));
}
