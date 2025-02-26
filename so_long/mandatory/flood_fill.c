/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-badd <mel-badd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 01:25:12 by mel-badd          #+#    #+#             */
/*   Updated: 2025/02/26 05:59:27 by mel-badd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// char	**dup_map(char **map, int rows)
// {
// 	char	**cmap;
// 	int		i;
// 	int		j;

// 	if (rows <= 0)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	cmap = malloc(sizeof(char *) * (rows + 1));
// 	if (!cmap)
// 		return (NULL);
// 	while (map[i])
// 	{
// 		cmap[j] = ft_strdup(map[i]);
// 		if (!cmap[j])
// 			return (free(cmap), NULL);
// 		j++;
// 		i++;
// 	}
// 	cmap[j] = (NULL);
// 	return (cmap);
// }

// static void	flood_fill(char **cmap, int x, int y, int rows, int colum)
// {
// 	if (x >= rows || y >= colum || x < 0 || y < 0)
// 		return ;
// 	if (cmap[y][x] == '1' || cmap[y][x] == 'V')
// 		return ;
// 	cmap[y][x] = 'V';
// 	flood_fill(cmap, x + 1, y, rows, colum);
// 	flood_fill(cmap, x - 1, y, rows, colum);
// 	flood_fill(cmap, x, y + 1, rows, colum);
// 	flood_fill(cmap, x, y - 1, rows, colum);
// }

// static int	*find_p(char **map)
// {
// 	int		i;
// 	int		k;
// 	int		*pos;

// 	i = 0;
// 	pos = malloc(sizeof(int) * 2);
// 	if (!pos)
// 		return (NULL);
// 	while (map[i])
// 	{
// 		k = 0;
// 		while (map[i][k])
// 		{
// 			if (map[i][k] == 'P')
// 			{
// 				pos[0] = i;
// 				pos[1] = k;
// 				return (pos);
// 			}
// 			k++;
// 		}
// 		i++;
// 	}
// 	free(pos);
// 	return (NULL);
// }

// void	invalid_path(char **map)
// {
// 	char	**cmap;
// 	int		*player;
// 	int		k;
// 	int		i;
// 	int		j;

// 	player = find_p(map);
// 	if (!player)
// 		exit(1);
// 	i = -1;
// 	while (map[++i]);
// 	cmap = dup_map(map, i);
// 	flood_fill(cmap, player[1], player[0], ft_strlen(map[0]), i);
// 	j = -1;
// 	while (map[++j])
// 	{
// 		k = -1;
// 		while (map[j][++k])
// 		{
// 			if (map[j][k] == 'C' || map[j][k] == 'E')
// 				if (cmap[j][k] != 'V')
// 				{
// 					perror("Invalid Path");
// 					exit(1);
// 				}
// 		}
// 	}
// }
void    free_map_copy(char **map)
{
    int    i;

    if (!map)
        return ;
    i = 0;
    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}
t_map	dup_map(t_map *map)
{
	t_map cmap;
	int i = 0;

	if (!map || map->row <= 0)
		return ((t_map){0});

	cmap.row = map->row;
	cmap.col = map->col;
	cmap.map = malloc(sizeof(char *) * (cmap.row + 1));
	if (!cmap.map)
		return ((t_map){0});

	while (i < cmap.row)
	{
		cmap.map[i] = ft_strdup(map->map[i]);
		if (!cmap.map[i])
		{
			while (--i >= 0)
				free(cmap.map[i]);
			free(cmap.map);
			return ((t_map){0});
		}
		i++;
	}
	cmap.map[i] = NULL;
	return cmap;
}
void	flood_fill(t_map *map, int x, int y)
{
	if (x < 0 || y < 0 || x >= map->col || y >= map->row)
		return;
	if (map->map[y][x] == '1' || map->map[y][x] == 'V')
		return;
	map->map[y][x] = 'V';

	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}
t_vector	find_p(t_map *map)
{
	t_vector pos = {-1, -1}; // Default to invalid position
	int i, j;

	if (!map || !map->map)
		return pos;

	for (i = 0; i < map->row; i++)
	{
		for (j = 0; j < map->col; j++)
		{
			if (map->map[i][j] == 'P')
			{
				pos.y = i;
				pos.x = j;
				return pos;
			}
		}
	}
	return pos;
}
void	invalid_path(t_map *map)
{
	t_map	cmap;
	t_vector	player;
	int i;
	int j;

	player = find_p(map);
	cmap = dup_map(map);
	i = 0;
	flood_fill(&cmap, player.x, player.y);
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			if ((map->map[i][j] == 'C' || map->map[i][j] == 'E') &&
				cmap.map[i][j] != 'V')
			{
				perror("Invalid Path");
				exit(1);
			}
			j++;
		}
		i++;
	}
	free_map_copy(cmap.map);
}
