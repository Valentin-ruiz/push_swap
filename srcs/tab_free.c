/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 11:03:42 by varuiz            #+#    #+#             */
/*   Updated: 2019/10/08 15:24:41 by varuiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tab_free(t_ab **ablst, int argc, char **argv, int len)
{
	if (argc > 1 && argv[1][0] != '\0')
	{
		if (len > 1 || argc > 2)
		{
			top_free((*ablst)->op);
			free((*ablst)->op);
			free((*ablst)->tab_med);
			free((*ablst)->stack_a);
			free((*ablst)->stack_b);
		}
	}
	ft_clear_pile((*ablst)->a);
	ft_clear_pile((*ablst)->b);
	free((*ablst)->a);
	free((*ablst)->b);
	free(*ablst);
	*ablst = NULL;
}

void	tdlist_free(t_node **alst)
{
	if (*alst)
	{
		free((*alst)->v);
		tdlist_free(&(*alst)->next);
		free(*alst);
		*alst = NULL;
	}
}

void	tcom_free(t_com **comlst)
{
	if (*comlst)
	{
		free((*comlst)->action);
		tcom_free(&(*comlst)->next);
		free(*comlst);
		*comlst = NULL;
	}
}

void	top_free(t_op **oplst)
{
	if (*oplst)
	{
		top_free(&(*oplst)->next);
		free(*oplst);
	}
}
