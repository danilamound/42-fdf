/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patigunt <patigunt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 21:43:49 by patigunt          #+#    #+#             */
/*   Updated: 2019/01/11 21:43:49 by patigunt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "mlx.h"
#include <fcntl.h>
#include <stdlib.h>

int		exit_response(char *reason)
{
	ft_putendl(reason);
	return (1);
}

int		main(int ac, char **av)
{
	t_map	*map;
	t_mlx	*mlx;
	int		fd;

	if (ac < 2)
		return (exit_response("error: you didn't point to a file"));
	fd = open(av[1], O_RDONLY);
	if (fd < 0 || !read_fdf(fd, &map))
		return (exit_response("error: fdf is wrong"));
	if ((mlx = init(ft_strjoin("FdF - ", av[1]))) == NULL)
		return (exit_response("error: mlx couldn't init"));
	mlx->map = map;
	render(mlx);
	mlx_key_hook(mlx->window, event_esc, mlx);
	mlx_hook(mlx->window, 4, 0, event_mousedown, mlx);
	mlx_hook(mlx->window, 5, 0, event_mouseup, mlx);
	mlx_hook(mlx->window, 6, 0, event_mousemove, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
