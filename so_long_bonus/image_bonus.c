/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyseo <jiyseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 00:16:47 by jiyseo            #+#    #+#             */
/*   Updated: 2022/07/03 03:14:56 by jiyseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	*img_load(void *mlx, char *file)
{
	void	*image;
	int		width;
	int		height;

	image = mlx_xpm_file_to_image(mlx, file, &width, &height);
	if (!image)
	{
		printf("%s image file error!\n", file);
		exit(0);
	}
	return (image);
}

t_data	img_init(void *mlx)
{
	t_data	image;

	image.land = img_load(mlx, "./images/land.xpm");
	image.wall = img_load(mlx, "./images/card.xpm");
	image.heart = img_load(mlx, "./images/heart.xpm");
	image.zomma = img_load(mlx, "./images/zomma.xpm");
	image.makao = img_load(mlx, "./images/makao.xpm");
	image.clear = img_load(mlx, "./images/clear.xpm");
	image.zzangu = img_load(mlx, "./images/zzangu.xpm");
	return (image);
}

void	img_put(t_game *game, int x, int y, void *img)
{
	mlx_put_image_to_window(game->mlx,
		game->win, img, x * GRID_WIDTH, y * GRID_HEIGHT);
}

void	img_draw(t_game *game, int x, int y, char ch)
{
	void	*img;

	if (ch == '1')
		img = game->img.wall;
	else if (ch == 'C')
		img = game->img.heart;
	else if (ch == 'P')
	{
		if (!game->gameover)
			img = game->img.zomma;
		else
			img = game->img.clear;
	}
	else if (ch == 'E')
		img = game->img.makao;
	else if (ch == 'X')
		img = game->img.zzangu;
	else
		img = game->img.land;
	if (img != game->img.land)
		img_put(game, x, y, game->img.land);
	img_put(game, x, y, img);
}
