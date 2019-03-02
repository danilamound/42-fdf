/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patigunt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 11:02:26 by patigunt          #+#    #+#             */
/*   Updated: 2018/09/16 11:02:36 by patigunt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t bytes;

	bytes = 0;
	while (bytes < len)
	{
		((char *)b)[bytes] = (unsigned char)c;
		bytes++;
	}
	return (b);
}
