/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsome.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patigunt <patigunt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 22:23:31 by patigunt          #+#    #+#             */
/*   Updated: 2018/09/28 12:05:26 by patigunt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsome(size_t size, char c)
{
	char	*str;
	int		i;

	if ((str = malloc(size)) == NULL)
		return (NULL);
	i = 0;
	while ((size_t)i < size)
	{
		*(str + i) = c;
		i++;
	}
	return (str);
}
