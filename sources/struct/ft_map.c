/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbelin <rbelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 14:43:24 by rbelin            #+#    #+#             */
/*   Updated: 2015/12/06 02:02:48 by rbelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

static char	*ft_linenew(int size)
{
	int	i;
	char	*ret;

	i = 0;
	if ((ret = (char *)malloc(sizeof(char) * (size + 1))))
	{
		while (i < size)
		{
			ret[i] = '.';
			++i;
		}
		ret[i] = '\0';
	}
	return (ret);
}

t_map		*ft_mapinit(int size)
{
	t_map	*map;
	int	i;

	i = 0;
	if ((map = (t_map *)malloc(sizeof(t_map))))
	{
		if ((map->byte = (char **)malloc(sizeof(char *) * (size))))
		{
			while (i < size)
			{
				if (!(map->byte[i] = ft_linenew(size)))
				{
					ft_mapdel(&map);
					break;
				}
				i++;
			}
		}
		else
			ft_mapdel(&map);
		map->size = i;
	}
	return (map);
}

t_map		*ft_mapdup(t_map *map)
{
	t_map	*new;

	if ((new = (t_map *)malloc(sizeof(t_map))))
	{
		new->size = 0;
		if ((new->byte = (char **)malloc(sizeof(char *) * (map->size))))
		{
			while (new->size < map->size)
			{
				if (!(new->byte[new->size] =
							ft_strdup(map->byte[new->size])))
				{
					ft_mapdel(&new);
					break;
				}
				new->size++;
			}
		}
		else
			ft_mapdel(&new);
	}
	return (new);
}

void		ft_mapdel(t_map **map)
{
	if (map && *map)
	{
		if ((*map)->byte)
			ft_astrdel(&(*map)->byte, (*map)->size);
		free(*map);
		*map = NULL;
	}
}
