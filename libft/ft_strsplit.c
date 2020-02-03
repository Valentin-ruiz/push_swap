/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 04:10:41 by varuiz            #+#    #+#             */
/*   Updated: 2019/03/25 16:06:38 by varuiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		word_compt(char const *s, char c)
{
	int p;
	int compteur;

	p = 0;
	compteur = 0;
	while (*s != '\0')
	{
		if (*s != c && p == 0)
		{
			p = 1;
			compteur++;
		}
		if (*s == c && p == 1)
			p = 0;
		s++;
	}
	return (compteur);
}

static int		len_word(char const *s, char c)
{
	int compteur;

	compteur = 0;
	while (*s != '\0' && *s != c)
	{
		compteur++;
		s++;
	}
	return (compteur);
}

char			**ft_strsplit(char const *s, char c)
{
	int			i;
	char		**tab;
	int			word;

	i = 0;
	if (s == NULL)
		return (NULL);
	word = word_compt(s, c);
	tab = (char **)malloc(sizeof(*tab) * (word + 1));
	if (tab == NULL)
		return (NULL);
	while (word > 0)
	{
		while (*s == c && *s != '\0')
			s++;
		tab[i] = ft_strsub(s, 0, len_word(s, c));
		if (tab[i] == NULL)
			return (NULL);
		s = s + len_word(s, c);
		i++;
		word--;
	}
	tab[i] = NULL;
	return (tab);
}
