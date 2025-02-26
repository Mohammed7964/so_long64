/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-badd <mel-badd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:46:46 by mel-badd          #+#    #+#             */
/*   Updated: 2025/02/23 00:01:46 by mel-badd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void get_player_position(t_program *game)
{
    int row;
    int col;

    row = 0;
    while (game->map.map[row])
    {
        col = 0;
        while (game->map.map[row][col])
        {
            if (game->map.map[row][col] == 'P')
            {
                game->map.player.x = row;
                game->map.player.y = col;
                printf("%d->%d", row, col);
                return;
            }
            col++;
        }
        row++;
    }
}

