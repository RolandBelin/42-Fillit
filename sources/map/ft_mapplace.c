/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapplace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbelin <rbelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 02:50:58 by rbelin            #+#    #+#             */
/*   Updated: 2015/12/06 02:53:10 by rbelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

static char	ft_mapcanplace(t_map *map, t_form *form, int x, int y)
{
	int	ix;
	int	iy;

	ix = 0;
	iy = 0;
	while (iy < form->max_y)
	{
		while (ix < form->max_x)
		{
			if (map->byte[iy + y][ix + x] != '.' &&
					form->map[iy][ix] != '.')
				return (0);
			++ix;
		}
		++iy;
		ix = 0;
	}
	return (1);
}

static void	ft_mapprint(t_map *map, t_type *type, int x, int y)
{
	int	ix;
	int	iy;

	ix = 0;
	iy = 0;
	while (iy < type->form->max_y)
	{
		while (ix < type->form->max_x)
		{
			if (type->form->map[iy][ix] != '.')
				map->byte[y + iy][x + ix] = type->letter;
			++ix;
		}
		++iy;
		ix = 0;
	}
}

char		ft_mapplace(t_map *map, t_type *type, int x, int y)
{
	if (!ft_mapcanplace(map, type->form, x, y))
		return (0);
	ft_mapprint(map, type, x, y);
	return (1);
}


