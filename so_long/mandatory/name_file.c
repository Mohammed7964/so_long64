/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-badd <mel-badd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:30:23 by mel-badd          #+#    #+#             */
/*   Updated: 2025/02/26 03:57:33 by mel-badd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int name_file(char *av)
{
    int len = ft_strlen(av);
    if (len < 4)
        return 0;
    if (ft_strcmp(av + len - 4, ".ber") == 0)
        return 1;
    return 0;
}
