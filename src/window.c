/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patigunt <patigunt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 21:43:16 by patigunt          #+#    #+#             */
/*   Updated: 2019/01/11 21:43:17 by patigunt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "fdf.h"

t_mlx		*mlx_exit_clean(t_mlx *mlx)
{
	if (mlx->window)
		mlx_destroy_window(mlx->mlx, mlx->window);
	if (mlx->cam)
		ft_memdel((void **)&mlx->cam);
	if (mlx->mouse)
		ft_memdel((void **)&mlx->mouse);
	if (mlx->image)
		del_image(mlx, mlx->image);
	ft_memdel((void **)&mlx);
	return (NULL);
}

t_mlx		*init(char *title)
{
	t_mlx	*mlx;

	if ((mlx = ft_memalloc(sizeof(t_mlx))) == NULL)
		return (NULL);
	if ((mlx->mlx = mlx_init()) == NULL ||
		(mlx->window = mlx_new_window(mlx->mlx, WIN_WIDTH,
			WIN_HEIGHT, title)) == NULL ||
		(mlx->cam = ft_memalloc(sizeof(t_cam))) == NULL ||
		(mlx->mouse = ft_memalloc(sizeof(t_mouse))) == NULL ||
		(mlx->image = new_image(mlx)) == NULL)
		return (mlx_exit_clean(mlx));
	mlx->cam->x = 0.5;
	mlx->cam->y = 0.5;
	mlx->cam->scale = 32;
	mlx->cam->offsetx = WIN_WIDTH / 2;
	mlx->cam->offsety = WIN_HEIGHT / 2;
	return (mlx);
}
