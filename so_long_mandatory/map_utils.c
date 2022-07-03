/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyseo <jiyseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 01:25:58 by jiyseo            #+#    #+#             */
/*   Updated: 2022/07/03 15:03:48 by jiyseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_init(t_game *game)
{
	game->height = 0;
	game->width = 0;
	game->zomma_pt.x = 0;
	game->zomma_pt.y = 0;
	game->str_map = NULL;
	game->str_map2 = NULL;
	game->all_col = 0;
	game->col_cnt = 0;
	game->walk_cnt = 0;
	game->zomma_cnt = 0;
	game->makao_cnt = 0;
	game->gameover = 0;
	game->fps = 0;
}

char	*map_readline(int fd)
{
	char	*line;
	char	*s;

	line = get_next_line(fd);
	if (line == NULL)
		return (NULL);
	s = line;
	while (*s && *s != '\n')
		s++;
	*s = '\0';
	return (line);
}

int	map_join(t_game *game, char *s)
{
	char	*new_mem;
	int		len;
	int		s_len;

	if (!game->str_map || !s)
		return (0);
	s_len = ft_strlen(s);
	if (s_len != game->width)
		return (ERR_MAP);
	len = ft_strlen(game->str_map);
	new_mem = malloc(len + s_len + 1);
	if (!new_mem)
		return (ERR_MEMORY);
	ft_strlcpy(new_mem, game->str_map, len + 1);
	ft_strlcpy(new_mem + len, s, s_len + 1);
	free(game->str_map);
	free(s);
	game->str_map = new_mem;
	return (1);
}

int	map_check(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->width)
	{
		if (map_get(game, i, 0) != '1'
			|| map_get(game, i, game->height - 1) != '1')
			return (ERR_MAP);
		i++;
	}
	i = 1;
	while (i < game->height - 1)
	{
		if (map_get(game, 0, i) != '1'
			|| map_get(game, game->width - 1, i) != '1')
			return (ERR_MAP);
		i++;
	}
	return (1);
}
