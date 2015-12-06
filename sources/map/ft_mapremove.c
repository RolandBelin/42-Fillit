/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbelin <rbelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 02:54:39 by rbelin            #+#    #+#             */
/*   Updated: 2015/12/06 02:55:00 by rbelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

static void	ft_maprmrecursive(t_map *map, int x, int y, char letter)
{
	map->byte[y][x] = '.';
	if (y > 0 && map->byte[y - 1][x] == letter)
		ft_maprmrecursive(map, x, y - 1, letter);
	if (x > 0 && map->byte[y][x - 1] == letter)
		ft_maprmrecursive(map, x - 1, y, letter);
	if (y + 1 < map->size && map->byte[y + 1][x] == letter)
		ft_maprmrecursive(map, x, y + 1, letter);
	if (x + 1 < map->size && map->byte[y][x + 1] == letter)
		ft_maprmrecursive(map, x + 1, y, letter);
}

void		ft_mapremove(t_map *map, t_type *type)
{
	while (type->pos_x < map->size)
	{
		if (map->byte[type->pos_y][type->pos_x] == type->letter &&
			map->byte[type->pos_y][type->pos_x] != '.')
		{
			ft_maprmrecursive(map, type->pos_x,
				type->pos_y, type->letter);
			return ;
		}
		++type->pos_x;
	}
}
