/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndebiesm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 09:55:01 by ndebiesm          #+#    #+#             */
/*   Updated: 2019/10/28 08:19:44 by ndebiesm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	**ft_freemysplit(unsigned int j, char **split)
{
	while (j != 0)
		free(split[--j]);
	free(split);
	return (NULL);
}

static	char	**ft_protect(void)
{
	char	**str;

	str = malloc(sizeof(char *));
	if (str == NULL)
		return (0);
	str[0] = 0;
	return (str);
}

static int		ft_words_count(char const *str, char c)
{
	int		i;
	int		wc;

	i = 0;
	wc = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			wc++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (wc);
}

static char		*ft_add_word(char const *str, char c)
{
	int		i;
	char	*lstr;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	lstr = malloc(sizeof(char) * i);
	if (lstr == NULL)
		return (0);
	i = 0;
	while (str[i] && str[i] != c)
	{
		lstr[i] = str[i];
		i++;
	}
	lstr[i] = '\0';
	return (lstr);
}

char			**ft_split(char const *str, char c)
{
	int		i;
	int		j;
	char	**split;

	i = 0;
	j = 0;
	if (ft_strlen(str) == 0)
		return (ft_protect());
	if (!(split = malloc(sizeof(char *) * (ft_words_count(str, c) + 1))))
		return (0);
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			if (!(split[j] = ft_add_word(&str[i], c)))
				return (ft_freemysplit(--j, split));
			j++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	split[j] = 0;
	return (split);
}
