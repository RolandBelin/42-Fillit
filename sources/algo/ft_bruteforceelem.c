/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bruteforceelem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbelin <rbelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 02:56:41 by rbelin            #+#    #+#             */
/*   Updated: 2015/12/06 03:04:45 by rbelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

static char	ft_bruteforceplace(t_map *map, t_type *type)
{
	type->pos_x = 0;
	type->pos_y = 0;
	while (type->pos_y <= type->form->map_my)
	{
		while (type->pos_x <= type->form->map_mx)
		{
			if (ft_mapplace(map, type, type->pos_x, type->pos_y))
				return (1);
			++type->pos_x;
		}
		type->pos_x = 0;
		++type->pos_y;
	}
	type->pos_x = -1;
	type->pos_y = -1;
	return (0);
}

static char	ft_bruteforceprint(t_fillit *fillit, int *id)
{
	if (fillit->alltype[*id]->printed)
		return (1);
	else if (!ft_bruteforceplace(fillit->beta, fillit->alltype[*id]))
		return (0);
	fillit->alltype[*id]->printed = 1;
	++fillit->totalprinted;
	return (1);
}

static void	ft_bruteforceremove(t_fillit *fillit, int *id)
{
	ft_mapremove(fillit->beta, fillit->alltype[*id]);
	fillit->alltype[*id]->pos_x = -1;
	fillit->alltype[*id]->pos_y = -1;
	fillit->alltype[*id]->printed = 0;
	--fillit->totalprinted;
}

char		ft_bruteforceelem(t_fillit *fillit, int *id)
{
	int	i;

	i = 0;
	if (!ft_bruteforceprint(fillit, id) ||
			((++fillit->bruteforce_hit) > D_BRUTEFORCE_HIT))
		return (0);
	while (i < fillit->totaltype)
	{
		if (!fillit->alltype[i]->printed)
		{
			if(ft_bruteforceelem(fillit, &i))
				return (1);
			else if (fillit->alltype[i]->printed)
				ft_bruteforceremove(fillit, &i);
		}
		++i;
	}
	if (fillit->totalprinted == fillit->totaltype)
		return (1);
	if (fillit->alltype[*id]->printed)
		ft_bruteforceremove(fillit, id);
	return (0);
}
