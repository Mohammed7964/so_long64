/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-badd <mel-badd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:28:00 by mel-badd          #+#    #+#             */
/*   Updated: 2025/02/26 06:04:01 by mel-badd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_close(void)
{
	write(2, "WINDOW CLOSED!", 14);
    // free(game);
	exit(1);
}

void format(char *av, t_program game)
{
	int tol = 0;
	int ard = 0;
    int fd = open(av, O_RDONLY);
    char *line = get_next_line(fd);
    ard = ft_strlen(line) - 1;
    while (line)
    {
        free(line);
        line = get_next_line(fd);
        tol++;
    }
    ard *= TILE_SIZE;
    tol *= TILE_SIZE;
    game.win_ptr = mlx_new_window(game.mlx, ard, tol, "MiniLibX Window");
	if(ft_render_images(game) == 0)
		exit (1);
	mlx_hook(game.win_ptr, 2, 0, ft_input, &game);
	mlx_hook(game.win_ptr, WIN_CLOSE, 0, ft_close, NULL);
    mlx_loop(game.mlx);
}
