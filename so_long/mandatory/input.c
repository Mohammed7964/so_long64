/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-badd <mel-badd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:34:09 by mel-badd          #+#    #+#             */
/*   Updated: 2025/02/25 22:01:51 by mel-badd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_input(int key, void *param)
{
	t_program	*game;

	printf("Input received: %d\n", key);
	game = (t_program *)param;
	// if (key == WIN_CLOSE)
	// 	exit(1);
	if (key == ESC_KEY)
		exit(1);
	else if (key == UP_KEY)
		move_up(game);
	else if (key == DOWN_KEY)
		move_down(game);
	else if (key == RIGHT_KEY)
		move_right(game);
	else if (key == LEFT_KEY)
		move_left(game);
	mlx_clear_window(game->mlx, game->win_ptr);
	// update_player_position(game);
	ft_render_images(*game);
	return (0);
}
