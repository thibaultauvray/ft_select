/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <tauvray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:58:43 by tauvray           #+#    #+#             */
/*   Updated: 2015/03/21 12:17:15 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*map;
	size_t	i;

	i = 0;
	map = NULL;
	if (s && f)
	{
		map = (char *)malloc(sizeof(char) * ft_strlen((char *)s) + 1);
		while (i < ft_strlen((char *)s))
		{
			map[i] = f(i, s[i]);
			i++;
		}
	}
	return (map);
}
