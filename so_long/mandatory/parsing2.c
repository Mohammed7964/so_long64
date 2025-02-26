/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-badd <mel-badd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:05:27 by mel-badd          #+#    #+#             */
/*   Updated: 2025/02/26 06:08:55 by mel-badd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1')
		{
			free(line);
			exit(1);
		}
		i++;
	}
	return (1);
}


int	valide_character(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != '1' && map[i] != '0' && map[i] != 'P' &&
			map[i] != 'E' && map[i] != 'C' && map[i] != '\n')
			return (0);
		if (map[i + 1] == '\n' && map[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

void one_line(char *line1, char *line2)
{
	if (line1[0] != '1' || !valide_character(line1) ||
		ft_strlen(line1) != ft_strlen(line2))
	{
		free(line1);
		free(line2);
		exit(1);
	}

}
char *read_lines(int fd, char **str)
{
    char *line1;
    char *line2;
    char *temp;

    line1 = get_next_line(fd);
    line2 = get_next_line(fd);
    if (!line1 || !line2)
        return NULL;
	if (ft_strlen(line1) >= 80)
		return NULL;
    *str = ft_strdup(line1);
    if (!*str || !check_line(line1))
        return NULL;
    while (line1 && line2)
    {
        one_line(line1, line2);
			free(line1);
        temp = ft_strjoin(*str, line2);
        if (!temp)
            exit(1);  // Handle error appropriately in real applications
        *str = temp;
        line1 = line2;
        line2 = get_next_line(fd);
    }
	free(line1);
    return temp;  // Return the last line
}
