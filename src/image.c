/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patigunt <patigunt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 21:44:06 by patigunt          #+#    #+#             */
/*   Updated: 2019/01/11 21:44:06 by patigunt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "mlx.h"

void	image_set_pxl(t_image *image, int x, int y, int color)
{
	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
		*(int *)(image->ptr + ((x + y * WIN_WIDTH) * image->bpp)) = color;
}

void	clear_image(t_image *image)
{
	ft_bzero(image->ptr, WIN_WIDTH * WIN_HEIGHT * image->bpp);
}

t_image	*del_image(t_mlx *mlx, t_image *img)
{
	if (img)
	{
		if (img->image)
			mlx_destroy_image(mlx->mlx, img->image);
		ft_memdel((void **)&img);
	}
	return (NULL);
}

t_image	*new_image(t_mlx *mlx)
{
	t_image		*img;

	if ((img = ft_memalloc(sizeof(t_image))) == NULL)
		return (NULL);
	if ((img->image = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT)) == NULL)
		return (del_image(mlx, img));
	img->ptr = mlx_get_data_addr(img->image, &img->bpp, &img->stride,
			&img->endian);
	img->bpp /= 8;
	return (img);
}
