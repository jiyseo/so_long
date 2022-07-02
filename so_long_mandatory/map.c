/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyseo <jiyseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 00:28:00 by jiyseo            #+#    #+#             */
/*   Updated: 2022/07/03 03:30:12 by jiyseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		map_state(t_game *game);
int		map_check(t_game *game);
int		map_join(t_game *game, char *s);
char	*map_readline(int fd);
void	map_init(t_game *game);

char	map_get(t_game *game, int x, int y)
{
	return (game->str_map[y * game->width + x]);
}

void	map_put(t_game *game, int x, int y, char ch)
{
	game->str_map[y * game->width + x] = ch;
}

static int	map_read(t_game *game, char *filename)
{
	int	fd;
	int	ret;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ERR_FILE_OPEN);
	game->str_map = map_readline(fd);
	if (!game->str_map || !*game->str_map)
		return (ERR_MAP);
	game->height++;
	game->width = ft_strlen(game->str_map);
	while (1)
	{
		ret = map_join(game, map_readline(fd));
		if (ret <= 0)
			break ;
		game->height++;
	}
	close(fd);
	return (ret);
}

int	map_load(t_game *game, char *filename)
{
	int	ret;
	int	size;

	map_init(game);
	ret = map_read(game, filename);
	if (ret < 0)
		return (ret);
	if (ret == ERR_MAP || map_check(game) == ERR_MAP)
		return (ERR_MAP);
	if (map_state(game) == ERR_MAP)
		return (ERR_MAP);
	size = game->width * game->height + 1;
	game->str_map2 = malloc(size);
	if (!game->str_map2)
		return (ERR_MEMORY);
	while (--size >= 0)
		game->str_map2[size] = '\0';
	return (0);
}

void	map_paint(t_game *game)
{
	int		i;

	i = game->width * game->height;
	while (--i >= 0)
	{
		if (game->str_map[i] != game->str_map2[i])
		{
			game->str_map2[i] = game->str_map[i];
			img_draw(game, i % game->width, i / game->width, game->str_map[i]);
		}
	}
}
