/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyseo <jiyseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 01:29:15 by jiyseo            #+#    #+#             */
/*   Updated: 2022/07/03 06:33:03 by jiyseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_swap(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

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

static void	put_zzangu(t_game *game, int x, int y, char ch)
{
	map_put(game, game->zzangu_pt.x, game->zzangu_pt.y, '0');
	map_put(game, x, y, 'X');
	game->zzangu_pt.x = x;
	game->zzangu_pt.y = y;
	map_paint(game);
	if (ch == 'P')
		game->gameover = 1;
}

void	move_zzangu(t_game *game)
{
	int		i;
	int		x;
	int		y;
	char	ch;

	i = 0;
	while (i++ < 4)
	{
		x = game->zzangu_pt.x + game->zzangu_dirt.x;
		y = game->zzangu_pt.y + game->zzangu_dirt.y;
		ch = map_get(game, x, y);
		if (ch == '0' || ch == 'P')
		{
			put_zzangu(game, x, y, ch);
			break ;
		}
		game->zzangu_dirt.x = -game->zzangu_dirt.x;
		game->zzangu_dirt.y = -game->zzangu_dirt.y;
		if (i % 2 == 1)
			ft_swap(&game->zzangu_dirt.x, &game->zzangu_dirt.y);
	}
}
