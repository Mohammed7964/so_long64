/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-badd <mel-badd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:00:36 by mel-badd          #+#    #+#             */
/*   Updated: 2025/02/26 06:01:20 by mel-badd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include "../so_long.h"

int read_and_check_lines(int fd, char **str)
{
    char *last_line;

    last_line = read_lines(fd, str);
    if (!last_line)
    {
        free(last_line);
        exit(1);
    }
    // invalid_path(ft_split(*str, '\n'));
    return check_line(last_line);
}

int	valide_size(char *av, char **str)
{
	int	fd;
	int	result;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (write(2, "Error opening file\n", 19), 0);
	result = read_and_check_lines(fd, str);
	close(fd);
	return (result);
}


static int process_map(char *av, t_program *game, char **str)
{
    // Validate size and read the file into str
    if (!valide_size(av, str))
    {
        free(*str);
        exit(1);  // Indicate failure
    }
    game->map.map = ft_split(*str, '\n');
    if (!game->map.map)
    {
        free(*str);
        return 0;  // Indicate failure
    }

    return 1;  // Indicate success
}

void *parsing(char *av, t_program *game)
{
    char *str = NULL;
    int rows = 0;
    int cols;

    process_map(av, game, &str);
    while (game->map.map[rows])
    {
        cols = ft_strlen(game->map.map[rows]);
        rows++;
    }
    game->map.row = rows;
    game->map.col = cols;
    if (!check_size(&game->map)) // Ensure check_size returns 0 on failure instead of exiting
    {
    write(2, "File is invalid!\n", 17);
    free(str);
    return NULL; // Indicate failure without exiting
    }
    invalid_path(&game->map);
    printf("File is valid!\n");
    free(str);
    return game;
}
