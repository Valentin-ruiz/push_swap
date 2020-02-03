/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 15:04:37 by varuiz            #+#    #+#             */
/*   Updated: 2019/05/14 22:48:21 by varuiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_com		*ft_newcom(char *command, t_com **com)
{
	t_com *newcom;
	t_com *tmp;

	tmp = *com;
	if (!(newcom = (t_com*)malloc(sizeof(t_com))))
		return (NULL);
	newcom->action = ft_strdup(command);
	newcom->next = NULL;
	if (*com == NULL)
		*com = newcom;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = newcom;
	}
	return (newcom);
}

void		ft_getcom(t_com **com)
{
	char	*str;

	str = NULL;
	while (get_next_line(0, &str) == 1)
	{
		ft_newcom(ft_checkcom(str), com);
		ft_strdel(&str);
	}
}

char		*ft_checkcom(char *str)
{
	if (ft_strcmp("sa", str) != 0
		&& ft_strcmp("sb", str) != 0
		&& ft_strcmp("ss", str) != 0
		&& ft_strcmp("ra", str) != 0
		&& ft_strcmp("rb", str) != 0
		&& ft_strcmp("rr", str) != 0
		&& ft_strcmp("rrr", str) != 0
		&& ft_strcmp("rra", str) != 0
		&& ft_strcmp("rrb", str) != 0
		&& ft_strcmp("pb", str) != 0
		&& ft_strcmp("pa", str) != 0)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	return (str);
}

int			ft_convert_com_to_enum(char *com)
{
	if (ft_strcmp("sa", com) == 0)
		return (0);
	if (ft_strcmp("sb", com) == 0)
		return (1);
	if (ft_strcmp("ss", com) == 0)
		return (2);
	if (ft_strcmp("pa", com) == 0)
		return (3);
	if (ft_strcmp("pb", com) == 0)
		return (4);
	if (ft_strcmp("ra", com) == 0)
		return (5);
	if (ft_strcmp("rb", com) == 0)
		return (6);
	if (ft_strcmp("rr", com) == 0)
		return (7);
	if (ft_strcmp("rra", com) == 0)
		return (8);
	if (ft_strcmp("rrb", com) == 0)
		return (9);
	if (ft_strcmp("rrr", com) == 0)
		return (10);
	return (-1);
}

void		ft_execute(t_ab *pile, t_com *com)
{
	while (com)
	{
		do_op(pile, ft_convert_com_to_enum(com->action));
		com = com->next;
	}
}
