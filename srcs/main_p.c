/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 23:21:41 by varuiz            #+#    #+#             */
/*   Updated: 2019/10/08 15:27:22 by varuiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ab	*ft_init_pile(void)
{
	t_ab	*pile;
	t_dlist	*a;
	t_dlist	*b;

	a = dlist_new();
	b = dlist_new();
	pile = (t_ab*)malloc(sizeof(t_ab));
	pile->a = a;
	pile->b = b;
	pile->size = 0;
	pile->print = 1;
	pile->min = 0;
	return (pile);
}

void	ft_resolve(t_ab *pile, int nb_elem)
{
	ft_cocktail_simple(pile->b);
	ft_prepare(pile, nb_elem);
	ft_clear_pile(pile->b);
	if (!(pile->op = (t_op**)ft_memalloc(sizeof(t_op*))))
		exit(ft_end(4));
	if (ft_sort(pile->a) || nb_elem < 2)
		return ;
	if (pile->a->len < 4)
	{
		ft_algo(pile);
		if (ft_sort(pile->a))
			proceed_op(pile, -1);
	}
	if (!ft_sort(pile->a))
	{
		delete_ops(pile->op);
		quick_sort(pile);
		proceed_op(pile, -1);
	}
}

void	normal_way(int argc, char **argv, t_ab *pile)
{
	int		i;
	int		y;

	i = 1;
	y = 0;
	if (!(pile->stack_a = ft_memalloc(sizeof(int) * (argc - 1)))
		|| !(pile->stack_b = ft_memalloc(sizeof(int) * (argc - 1)))
		|| !(pile->tab_med = ft_memalloc(sizeof(int) * (argc - 1))))
		exit(ft_end(4));
	while (argv[i])
	{
		if (ft_is_number(argv[i]) && ft_is_valid(argv[i])
			&& ft_no_double(pile->a->head, ft_atoi(argv[i])))
		{
			dlist_push_back(pile->a, ft_atoi(argv[i]), 0);
			dlist_push_back(pile->b, ft_atoi(argv[i]), 0);
			pile->stack_a[y] = ft_atoi(argv[i]);
			y++;
		}
		else
			ft_print_error();
		i++;
	}
	ft_resolve(pile, argc - 1);
}

void	tab_way(t_ab *pile, char **tab, int len)
{
	int		j;
	int		y;

	j = 0;
	y = 0;
	if (!(pile->stack_a = ft_memalloc(sizeof(int) * len))
		|| !(pile->stack_b = ft_memalloc(sizeof(int) * len))
		|| !(pile->tab_med = ft_memalloc(sizeof(int) * len)))
		exit(ft_end(4));
	while (tab[j])
	{
		if (ft_is_number(tab[j]) && ft_is_valid(tab[j])
			&& ft_no_double(pile->a->head, ft_atoi(tab[j])))
		{
			dlist_push_back(pile->a, ft_atoi(tab[j]), 0);
			dlist_push_back(pile->b, ft_atoi(tab[j]), 0);
			pile->stack_a[y] = ft_atoi(tab[j]);
			y++;
		}
		else
			ft_print_error();
		j++;
	}
	ft_resolve(pile, j);
}

int		main(int argc, char **argv)
{
	t_ab	*pile;
	char	**tab;
	int		len;
	int		j;

	pile = ft_init_pile();
	j = 0;
	len = 0;
	if (argc == 2 && argv[1][0] != '\0')
	{
		tab = ft_strsplit(argv[1], ' ');
		while (tab[len++])
			;
		len == 1 ? NULL : tab_way(pile, tab, len - 1);
		while (tab[j])
		{
			free(tab[j]);
			j++;
		}
		free(tab);
	}
	else if (argc > 2)
		normal_way(argc, argv, pile);
	tab_free(&pile, argc, argv, len);
	return (0);
}
