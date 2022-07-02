/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_state_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyseo <jiyseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 01:25:49 by jiyseo            #+#    #+#             */
/*   Updated: 2022/07/03 05:31:18 by jiyseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	map_info(t_game *game, char *str)
{
	int	idx;

	if (*str == 'C')
		game->all_col++;
	else if (*str == 'E')
		game->makao_cnt++;
	else if (*str == 'X')
	{
		game->zzangu_cnt++;
		idx = (int)(str - game->str_map);
		game->zzangu_pt.x = idx % game->width;
		game->zzangu_pt.y = idx / game->width;
	}
	else if (*str == 'P')
	{
		game->zomma_cnt++;
		idx = (int)(str - game->str_map);
		game->zomma_pt.x = idx % game->width;
		game->zomma_pt.y = idx / game->width;
	}
}

int	map_state(t_game *game)
{
	char	*str;

	str = game->str_map;
	while (*str)
		map_info(game, str++);
	if (game->zomma_cnt != 1 || game->makao_cnt != 1
		|| game->zzangu_cnt != 1 || game->all_col < 1)
		return (ERR_MAP);
	game->zzangu_dirt.x = -1;
	game->zzangu_dirt.y = 0;
	return (1);
}
