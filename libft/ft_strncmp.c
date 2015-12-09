/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <tauvray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:26:59 by tauvray           #+#    #+#             */
/*   Updated: 2015/10/19 12:57:44 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		cmp;

	cmp = 0;
	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n && cmp == 0)
	{
		cmp = s1[i] - s2[i];
		i++;
	}
	return (cmp);
}
