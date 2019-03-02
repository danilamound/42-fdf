/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patigunt <patigunt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 21:43:34 by patigunt          #+#    #+#             */
/*   Updated: 2019/01/20 13:13:46 by patigunt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "libft.h"

int			height_color(int c1, int c2, double p)
{
	if (p >= 0.99)
		return (0xFFFFFF);
	else
		return (gradient(c1, c2, p));
}

int			mix_hex(int first, int second, double p)
{
	if (first == second)
		return (first);
	return ((int)((double)first + (second - first) * p));
}

int			gradient(int c1, int c2, double p)
{
	int r;
	int g;
	int b;

	if (c1 == c2)
		return (c1);
	r = mix_hex((c1 >> 16) & 0xFF, (c2 >> 16) & 0xFF, p);
	g = mix_hex((c1 >> 8) & 0xFF, (c2 >> 8) & 0xFF, p);
	b = mix_hex(c1 & 0xFF, c2 & 0xFF, p);
	return (r << 16 | g << 8 | b);
}

void		render(t_mlx *mlx)
{
	int			x;
	int			y;
	t_vector	v;
	t_map		*map;

	map = mlx->map;
	clear_image(mlx->image);
	x = 0;
	while (x < map->width)
	{
		y = 0;
		while (y < map->height)
		{
			v = set_vector(vector_at(map, x, y), mlx);
			if (x + 1 < map->width)
				line(mlx, v, set_vector(vector_at(map, x + 1, y), mlx));
			if (y + 1 < map->height)
				line(mlx, v, set_vector(vector_at(map, x, y + 1), mlx));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image->image, 0, 0);
}
