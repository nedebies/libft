/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nedebies <nedebies@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:39:12 by nedebies          #+#    #+#             */
/*   Updated: 2021/03/17 20:39:13 by nedebies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin(char const *str1, char const *str2)
{
	char				*str;
	unsigned int		i;

	i = 0;
	if (str1 == NULL && str2 == NULL)
		return (0);
	if (str1 == NULL)
		return ((char *)str2);
	if (str2 == NULL)
		return ((char *)str1);
	if (!(str = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2)) + 1)))
		return (0);
	while (*str1)
		str[i++] = *str1++;
	while (*str2)
		str[i++] = *str2++;
	str[i] = 0;
	return (str);
}
