/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-badd <mel-badd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:59:01 by mel-badd          #+#    #+#             */
/*   Updated: 2025/02/26 06:16:29 by mel-badd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void f()
{
    system("leaks so_long");
}
int main(int ac, char **av)
{
    t_program	game;

    atexit(f);
    if (ac == 2)
    {
	    if (!name_file(av[1]))
		    handle_error();
	    parsing(av[1], &game);
	    get_collectibles(&game);
	    get_player_position(&game);
	    game.mlx = mlx_init();
	    if (!game.mlx)
	    	handle_error();
	    format(av[1], game);
	    free(&game);
    }
    else
    {
        printf("Error: Invalid number of arguments\n");
        return 1;
    }
}
