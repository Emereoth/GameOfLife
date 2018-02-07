/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 15:55:38 by acottier          #+#    #+#             */
/*   Updated: 2016/03/21 14:56:44 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strdup(const char *s1)
{
	char	*res;
	int		i;

	i = ft_strlen(s1);
	if ((res = ft_strnew(i)) == NULL)
		return (0);
	res[i] = '\0';
	while (i--)
		res[i] = s1[i];
	return (res);
}
