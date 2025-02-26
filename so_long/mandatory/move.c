/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-badd <mel-badd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:33:10 by mel-badd          #+#    #+#             */
/*   Updated: 2025/02/26 03:38:14 by mel-badd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_swap(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	move_up(t_program *game)
{
	// int new_x = game->map.player.x - 1;
	if (game->map.map[game->map.player.x - 1][game->map.player.y] == '0')
	{
		ft_swap(&game->map.map[game->map.player.x - 1][game->map.player.y],
			&game->map.map[game->map.player.x][game->map.player.y]);
		game->map.player.x--;
		printf("[%sMOVED UP%s] - [%sCOUNT%s] > %zu\n", RED, END, YELLOW, END,
			++game->mv_count);
	}
	else if (game->map.map[game->map.player.x - 1][game->map.player.y] == 'C')
	{
		game->map.collectibles--;
		game->map.map[game->map.player.x][game->map.player.y] = '0';
		game->map.map[game->map.player.x - 1][game->map.player.y] = 'P';
		game->map.player.x--;
	}
	// else if (game->map.map[game->map.player.x - 1][game->map.player.y] == 'E')
	// {
	// 	game->map.map[game->map.player.x - 1][game->map.player.y] = 'P';
	// 	game->map.map[game->map.player.x][game->map.player.y] = 'E';
	// 	game->img_ptr = mlx_xpm_file_to_image(game->mlx, "sprites/close.xpm", &game->img_size, &game->img_size);
	// 	mlx_put_image_to_window(game->mlx, game->win_ptr, game->img_ptr, game->map.player.y * SQUARE, new_x * SQUARE);
	// 	game->img_ptr = mlx_xpm_file_to_image(game->mlx, "sprites/player.xpm", &game->img_size, &game->img_size);
	// 	mlx_put_image_to_window(game->mlx, game->win_ptr, game->img_ptr, game->map.player.y * SQUARE, game->map.player.x * SQUARE);
	// 	game->map.map[game->map.player.x][game->map.player.y] = '0';
	// 	game->map.player.x--;
	// }
	else if (game->map.map[game->map.player.x - 1][game->map.player.y] == 'E'
		&& !game->map.collectibles)
		{
			printf("%sYOUUUUUUUU WIIIIIIIIIN!%s", GREEN, GREEN);
			exit (1);
		}
}

void	move_down(t_program *game)
{
	if (game->map.map[game->map.player.x + 1][game->map.player.y] == '0')
	{
		ft_swap(&game->map.map[game->map.player.x + 1][game->map.player.y],
			&game->map.map[game->map.player.x][game->map.player.y]);
		game->map.player.x++;
		printf("[%sMOVED DOWN%s] - [%sCOUNT%s] > %zu\n", RED, END, YELLOW, END,
			++game->mv_count);
	}
	else if (game->map.map[game->map.player.x + 1][game->map.player.y] == 'C')
	{
		game->map.collectibles--;
		game->map.map[game->map.player.x][game->map.player.y] = '0';
		game->map.map[game->map.player.x + 1][game->map.player.y] = 'P';
		game->map.player.x++;
	}
	else if (game->map.map[game->map.player.x + 1][game->map.player.y] == 'E'
		&& !game->map.collectibles)
		{
			printf("[%sYOU WIN!%s]", GREEN, GREEN);
			exit (1);
		}
}

void	move_left(t_program *game)
{
	if (game->map.map[game->map.player.x][game->map.player.y - 1] == '0')
	{
		ft_swap(&game->map.map[game->map.player.x][game->map.player.y - 1],
			&game->map.map[game->map.player.x][game->map.player.y]);
		game->map.player.y--;
		printf("[%sMOVED LEFT%s] - [%sCOUNT%s] > %zu\n", RED, END, YELLOW, END,
			++game->mv_count);
	}
	else if (game->map.map[game->map.player.x][game->map.player.y - 1] == 'C')
	{
		game->map.collectibles--;
		game->map.map[game->map.player.x][game->map.player.y] = '0';
		game->map.map[game->map.player.x][game->map.player.y - 1] = 'P';
		game->map.player.y--;
	}
	else if (game->map.map[game->map.player.x][game->map.player.y - 1] == 'E'
		&& !game->map.collectibles)
		{
			printf("[%sYOU WIN!%s]", GREEN, GREEN);
			exit (1);
		}
}

void	move_right(t_program *game)
{
	if (game->map.map[game->map.player.x][game->map.player.y + 1] == '0')
	{
		ft_swap(&game->map.map[game->map.player.x][game->map.player.y + 1],
			&game->map.map[game->map.player.x][game->map.player.y]);
		game->map.player.y++;
		printf("[%sMOVED RIGHT%s] - [%sCOUNT%s] > %zu\n", RED, END, YELLOW, END,
			++game->mv_count);
	}
	else if (game->map.map[game->map.player.x][game->map.player.y + 1] == 'C')
	{
		game->map.collectibles--;
		game->map.map[game->map.player.x][game->map.player.y] = '0';
		game->map.map[game->map.player.x][game->map.player.y + 1] = 'P';
		game->map.player.y++;
	}
	else if (game->map.map[game->map.player.x][game->map.player.y + 1] == 'E'
		&& !game->map.collectibles)
		{
			printf("[%sYOU WIN!%s]", GREEN, GREEN);
			exit (1);
		}
}

