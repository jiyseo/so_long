/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyseo <jiyseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:11:43 by jiyseo            #+#    #+#             */
/*   Updated: 2022/07/03 03:15:51 by jiyseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int		game_init(t_game *game, char *map_file);
void	move_zzangu(t_game *game);

void	game_free(t_game *game)
{
	if (game->str_map)
		free(game->str_map);
	if (game->str_map2)
		free(game->str_map2);
	game->str_map = NULL;
	game->str_map2 = NULL;
}

void	game_exit(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	game_free(game);
	exit(0);
}

int	game_close(int key_code, t_game *game)
{
	exit(0);
}

int	game_loop(t_game *game)
{
	static int	loop_cnt = 0;

	if (++loop_cnt <= 100)
		return (0);
	loop_cnt = 0;
	if (++game->fps >= 1000)
		game->fps = 0;
	if (game->gameover && game->fps % 50 == 0)
		game_exit(game);
	if (game->fps % 20 == 0)
		move_zzangu(game);
	return (0);
}

int	main(int ac, char *av[])
{
	t_game	game;

	if (ac != 2)
		ft_printf("Map is missing.\n");
	if (!game_init(&game, av[1]))
		return (0);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 1, &press_key, &game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &game_close, &game);
	mlx_loop_hook(game.mlx, &game_loop, &game);
	mlx_loop(game.mlx);
	game_free(&game);
	return (0);
}
