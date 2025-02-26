/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_collectibles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-badd <mel-badd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:49:23 by mel-badd          #+#    #+#             */
/*   Updated: 2025/02/25 02:13:52 by mel-badd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void get_collectibles(t_program *game)
{
    int i, j;

    i = 0;
    while (game->map.map[i])
    {
        j = 0;
        while (game->map.map[i][j])
        {
            if (game->map.map[i][j] == 'C')
                game->map.collectibles++;
            j++;
        }
        i++;
    }
}
