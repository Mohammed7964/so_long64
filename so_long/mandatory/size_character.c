/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_character.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-badd <mel-badd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 21:41:27 by mel-badd          #+#    #+#             */
/*   Updated: 2025/02/25 20:02:09 by mel-badd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Function to count key elements with while loops
// static void count_elements_while(t_map *map, int *p, int *e, int *c)
// {
//     int i = 0;
//     while (i < map->row)
//     {
//         int j = 0;
//         while (j < map->col)
//         {
//             char cell = map->map[i][j];
//             if (cell == 'P')
//             {
//                 (*p)++;
//                 map->player.x = j;
//                 map->player.y = i;
//             }
//             else if (cell == 'E')
//                 (*e)++;
//             else if (cell == 'C')
//                 (*c)++;
//             j++;
//         }
//         i++;
//     }
// }

// // Function to check key element counts
// static int check_key_elements_while(int p, int e, int c)
// {
//     if (p != 1 || e != 1 || c == 0)
//         return (0); // Ensure 1 player, 1 exit, at least 1 collectible
//     return 1;
// }

// // Main check_size function
// int check_size(t_map *map)
// {
//     int p;
// 	int e;
// 	int c;

// 	p = 0;
// 	e = 0;
// 	c = 0;
//     count_elements_while(map, &p, &e, &c); // Count the elements using while loops
//     if(!check_key_elements_while(p, e, c))
//         {
//             free(map);
//             exit(1);
//         }
//     return 1; // Validate the counts
// }

static void free_map(t_map *map)
{
    if (!map || !map->map)
        return;

    int i = 0;
    while (i < map->row)
    {
        free(map->map[i]);
        i++;
    }
    free(map->map);
}

static void count_elements_while(t_map *map, int *p, int *e, int *c)
{
    int i = 0;
    while (i < map->row)
    {
        int j = 0;
        while (j < map->col)
        {
            char cell = map->map[i][j];
            if (cell == 'P')
            {
                (*p)++;
                map->player.x = j;
                map->player.y = i;
            }
            else if (cell == 'E')
                (*e)++;
            else if (cell == 'C')
                (*c)++;
            j++;
        }
        i++;
    }
}

// Function to check key element counts
static int check_key_elements_while(int p, int e, int c)
{
    return (p == 1 && e == 1 && c > 0); // Ensure 1 player, 1 exit, at least 1 collectible
}

// Main check_size function
int check_size(t_map *map)
{
    int p = 0, e = 0, c = 0;

    count_elements_while(map, &p, &e, &c); // Count the elements

    if (!check_key_elements_while(p, e, c))
    {
        write(2, "Invalid map structure!\n", 23);
        free_map(map); // Free allocated memory
        exit(1);
    }
    return 1; // Valid map
}
