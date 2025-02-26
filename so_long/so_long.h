/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-badd <mel-badd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 19:04:49 by mel-badd          #+#    #+#             */
/*   Updated: 2025/02/26 03:59:31 by mel-badd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/errno.h>
# include "mlx.h"
#include "get_next_line.h"

# define RIGHT_KEY 2
# define LEFT_KEY 0
# define DOWN_KEY 1
# define UP_KEY 13
# define ESC_KEY 53
# define WIN_CLOSE 17
# define WIN_WIDTH 800
# define WIN_HEIGHT 600

/* -------- MAP -------- */
# define BUFF_SIZE 256
# define WALL '1'
# define EMPTY '0'
# define COL 'C'
# define EXIT 'E'
# define PLAYER 'P'
# define ENEMY 'X'
# define SQUARE 32
#define TILE_SIZE 32

/* -------- ERRORS -------- */
# define MALLOC_ERROR "so_long: Malloc failed to allocate enough memory."
# define DIR_ERROR "Is a directory!."

/* -------- COLORS -------- */
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define END "\033[0m"

typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

// all info needed for the map
typedef struct s_map
{
	char		**map;
	char		**maps;
	int			col;
	int			row;
	int			collectibles;
	t_vector	player;
}				t_map;

typedef struct s_program
{
	void		*mlx;
	void		*win_ptr;
	int			img_size;
	int			col;
	int			row;
	t_map		**maps;
	t_map		map;
    void	 	*img_ptr;
    int     	*img_data;
	int			fd;
	int			can_exit;
	size_t		mv_count;
}				t_program;

size_t	ft_strlen(const char *s);
int name_file(char *av);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void *parsing(char *av, t_program *game);
char	*ft_strjoine(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *src);
void	move_up(t_program *game);
void	move_down(t_program *game);
void	move_left(t_program *game);
void	move_right(t_program *game);
int	ft_input(int key, void *param);
void format(char *av, t_program game);
int check_size(t_map *map);
void get_player_position(t_program *game);
void get_collectibles(t_program *game);
void check_map(char **av);
void	handle_error(void);
char *ft_strdup(const char *s);
int ft_strcmp(char *s1, char *s2);
void ft_frree(char *line);
// void    invalid_path(char **map);
void	invalid_path(t_map *map);
int	ft_render_images(t_program game);
char *read_lines(int fd, char **str);
int	valide_character(char *map);
int	check_line(char *line);
void update_player_position(t_program *game);
// void	invalid_path(t_map *map);
#endif
