/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyseo <jiyseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 00:21:14 by jiyseo            #+#    #+#             */
/*   Updated: 2022/07/03 03:15:01 by jiyseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	put_zomma(t_game *game, int x, int y, char ch)
{
	if (ch != 'X')
		ch = 'P';
	map_put(game, game->zomma_pt.x, game->zomma_pt.y, '0');
	map_put(game, x, y, ch);
	game->zomma_pt.x = x;
	game->zomma_pt.y = y;
	game->walk_cnt++;
	map_paint(game);
}

static void	move_zomma(t_game *game, int x_dirt, int y_dirt)
{
	int		x;
	int		y;
	char	ch;

	if (game->gameover)
		return ;
	x = game->zomma_pt.x + x_dirt;
	y = game->zomma_pt.y + y_dirt;
	ch = map_get(game, x, y);
	if (ch == '1')
		return ;
	if (ch == 'C')
		game->col_cnt++;
	if (ch == 'X')
		game->gameover = 1;
	else if (ch == 'E' && game->all_col == game->col_cnt)
		game->gameover = 1;
	if (ch != 'E' || game->gameover)
		put_zomma(game, x, y, ch);
}

int	press_key(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		game_exit(game);
	else if (key_code == KEY_W)
		move_zomma(game, 0, -1);
	else if (key_code == KEY_A)
		move_zomma(game, -1, 0);
	else if (key_code == KEY_S)
		move_zomma(game, 0, 1);
	else if (key_code == KEY_D)
		move_zomma(game, 1, 0);
	return (0);
}
