/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndebiesm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:32:00 by ndebiesm          #+#    #+#             */
/*   Updated: 2019/10/14 14:18:31 by ndebiesm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		char_in_set(char c, char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;
	int		i;

	i = 0;
	if (s1 == NULL || set == NULL)
		return ((char *)s1);
	while (char_in_set(s1[i], (char*)set) && s1[i])
		i++;
	start = i;
	i = ft_strlen(s1) - 1;
	while (char_in_set(s1[i], (char*)set) && i > start)
		i--;
	end = i;
	i = 0;
	str = malloc(sizeof(char) * (end - start + 2));
	if (str == NULL)
		return (str);
	while (start <= end)
		str[i++] = s1[start++];
	str[i] = 0;
	return (str);
}
