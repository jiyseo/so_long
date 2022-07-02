/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyseo <jiyseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 01:29:15 by jiyseo            #+#    #+#             */
/*   Updated: 2022/07/03 04:00:44 by jiyseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	game_error(int ret, char *map_file)
{
	if (ret == ERR_FILE_OPEN)
	{
		ft_printf("%s File open error\n", map_file);
		return (0);
	}
	if (ret == ERR_MAP)
	{
		ft_printf("%s Map error\n", map_file);
		return (0);
	}
	if (ret == ERR_MEMORY)
	{
		ft_printf("Memory error\n");
		return (0);
	}
	return (1);
}

int	game_init(t_game *game, char *map_file)
{
	int	ret;

	game->mlx = mlx_init();
	game->img = img_init(game->mlx);
	game->str_map = NULL;
	game->str_map2 = NULL;
	ret = map_load(game, map_file);
	if (!game_error(ret, map_file))
		return (0);
	game->win = mlx_new_window(game->mlx, game->width * GRID_WIDTH,
			game->height * GRID_HEIGHT, "so_long");
	map_paint(game);
	return (1);
}
