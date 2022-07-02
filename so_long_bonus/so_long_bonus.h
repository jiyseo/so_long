/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyseo <jiyseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:10:29 by jiyseo            #+#    #+#             */
/*   Updated: 2022/07/03 03:18:14 by jiyseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include <unistd.h>
# include <fcntl.h>

# define GRID_WIDTH		64
# define GRID_HEIGHT	64

# define ERR_FILE_OPEN	-1
# define ERR_MAP		-2
# define ERR_MEMORY		-3

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3
# define X_EVENT_KEY_EXIT			17

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct s_data
{
	void	*zomma;
	void	*makao;
	void	*wall;
	void	*land;
	void	*heart;
	void	*clear;
	void	*zzangu;

}				t_data;

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_data	img;
	int		width;
	int		height;
	char	*str_map;
	char	*str_map2;
	int		all_col;
	int		col_cnt;
	int		walk_cnt;
	int		zomma_cnt;
	int		makao_cnt;
	int		zzangu_cnt;
	int		gameover;
	t_point	zomma_pt;
	t_point	zzangu_pt;
	t_point	zzangu_dirt;
	int		fps;
}				t_game;

int		press_key(int key_code, t_game *game);
int		close_key(int key_code, t_game *game);
int		map_load(t_game *game, char *filename);
char	map_get(t_game *game, int x, int y);
void	map_put(t_game *game, int x, int y, char ch);
void	map_paint(t_game *game);
void	img_put(t_game *game, int x, int y, void *img);
void	img_draw(t_game *game, int x, int y, char ch);
void	game_exit(t_game *game);
t_data	img_init(void *mlx);

#endif
