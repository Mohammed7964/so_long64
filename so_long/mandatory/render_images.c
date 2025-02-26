/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-badd <mel-badd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:30:53 by mel-badd          #+#    #+#             */
/*   Updated: 2025/02/25 02:58:49 by mel-badd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_get_image(char c, int can_exit)
{
	char	*output;

	(void)can_exit;
	output = NULL;
	if (c == WALL)
		output = "sprites/wall.xpm";
	if (c == PLAYER)
		output = "sprites/player.xpm";
	else if (c == COL)
		output = "sprites/cole.xpm";
	else if (c == EXIT)
	{
		if (can_exit)
			output = "sprites/open.xpm";
		else
			output = "sprites/close.xpm";
	}
	return (output);
}

int	render_images_action(t_program *game, int x, int y)
{
	char	*img_path;

	if (game->map.collectibles == 0)
		game->can_exit = 1;
	img_path = ft_get_image(game->map.map[x][y], game->can_exit);
	if (img_path)
	{
		game->img_ptr = mlx_xpm_file_to_image(game->mlx, img_path, &game->img_size, &game->img_size);
		if (!game->img_ptr)
		{
			fprintf(stderr, "Error: Failed to load image %s\n", img_path);
			exit(1);
		}
		mlx_put_image_to_window(game->mlx, game->win_ptr, game->img_ptr, y * SQUARE, x * SQUARE);
	}
	return 1;
}

int	ft_render_images(t_program game)
{
	int		x;
	int		y;

	x = 0;
	game.img_size = SQUARE;
	while (game.map.map[x])
	{
		y = 0;
		while (game.map.map[x][y] != '\n' && game.map.map[x][y])
		{
			game.img_ptr = mlx_xpm_file_to_image(game.mlx, "sprites/flour.xpm", &game.img_size, &game.img_size);
			mlx_put_image_to_window(game.mlx, game.win_ptr, game.img_ptr, y * SQUARE, x * SQUARE);
			render_images_action(&game, x, y);
			y++;
		}
		x++;
	}
	return 1;
}
