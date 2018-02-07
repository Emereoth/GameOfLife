/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newtab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 10:19:00 by acottier          #+#    #+#             */
/*   Updated: 2016/03/23 11:21:35 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_newtab(int	size)
{
	char 		**res;

	res = (char **)malloc(sizeof(char*) * (size + 1));
	res[size] = NULL;
	return (res);
}
