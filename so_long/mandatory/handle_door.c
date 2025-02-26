/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_door.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-badd <mel-badd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 03:12:35 by mel-badd          #+#    #+#             */
/*   Updated: 2025/02/25 03:52:56 by mel-badd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void update_player_position(t_program *game)
{
	int x = game->map.player.x;
	int y = game->map.player.y;



    if (game->map.map[game->map.player.x][game->map.player.y] == 'E')
    {
       game->img_ptr = mlx_xpm_file_to_image(game->mlx, "sprites/close.xpm", &game->img_size, &game->img_size);
			mlx_put_image_to_window(game->mlx, game->win_ptr, game->img_ptr, y * SQUARE, x * SQUARE);
    }
    else
    {
       game->img_ptr = mlx_xpm_file_to_image(game->mlx, "sprites/flour.xpm", &game->img_size, &game->img_size);
			mlx_put_image_to_window(game->mlx, game->win_ptr, game->img_ptr, y * SQUARE, x * SQUARE);
    }
    game->map.map[game->map.player.y][game->map.player.x] = (game->map.map[game->map.player.y][game->map.player.x] == 'E') ? 'E' : '0'; // Preserve 'E' if it was there
    game->map.player.x = x;
    game->map.player.y = y;
    if (game->map.map[y][x] == 'E')
    {
       game->img_ptr = mlx_xpm_file_to_image(game->mlx, "sprites/close.xpm", &game->img_size, &game->img_size);
			mlx_put_image_to_window(game->mlx, game->win_ptr, game->img_ptr, y * SQUARE, x * SQUARE);
    }
   game->img_ptr = mlx_xpm_file_to_image(game->mlx, "sprites/player.xpm", &game->img_size, &game->img_size);
			mlx_put_image_to_window(game->mlx, game->win_ptr, game->img_ptr, y * SQUARE, x * SQUARE);
}
