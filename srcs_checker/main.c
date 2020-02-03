/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 23:21:41 by varuiz            #+#    #+#             */
/*   Updated: 2019/10/08 16:18:45 by varuiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_ab		*ft_init_pile(void)
{
	t_ab	*pile;
	t_dlist	*a;
	t_dlist	*b;

	a = dlist_new();
	b = dlist_new();
	if (!(pile = (t_ab *)malloc(sizeof(*pile))))
		return (NULL);
	pile->a = a;
	pile->b = b;
	pile->size = 0;
	pile->op = NULL;
	pile->print = 1;
	pile->min = 0;
	pile->len_b = 0;
	return (pile);
}

void		ft_exec_checker(t_ab *pile)
{
	t_com	*com;
	int		i;

	i = 0;
	com = NULL;
	if (!(pile->op = (t_op**)ft_memalloc(sizeof(t_op*))))
		exit(ft_end(4));
	ft_cocktail_simple(pile->b);
	i = pile->len_a;
	ft_getcom(&com);
	ft_execute(pile, com);
	if (is_sorted(pile->stack_a, pile->len_a, 0, 1) == 1
		&& i == pile->len_a)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	tcom_free(&com);
}

void		normal_way_checker(int argc, char **argv, t_ab *pile)
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
	pile->len_a = y;
	ft_exec_checker(pile);
}

void		tab_way_checker(t_ab *pile, char **tab, int len)
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
	pile->len_a = y;
	ft_exec_checker(pile);
}

int			main(int argc, char **argv)
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
		len == 1 ? NULL : tab_way_checker(pile, tab, len - 1);
		while (tab[j])
		{
			free(tab[j]);
			j++;
		}
		free(tab);
	}
	else if (argc > 2)
		normal_way_checker(argc, argv, pile);
	tab_free(&pile, argc, argv, len);
	return (0);
}
