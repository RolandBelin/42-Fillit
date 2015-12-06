/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bruteforce.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbelin <rbelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 18:22:50 by rbelin            #+#    #+#             */
/*   Updated: 2015/12/06 02:59:19 by rbelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

static void	ft_bruteforcemaxsearch(t_fillit *fillit, int size)
{
	int	i;
	t_type	*type;

	i = 0;
	while (i < fillit->totaltype)
	{
		type = fillit->alltype[i];
		type->form->map_my = size - type->form->max_y;
		type->form->map_mx = size - type->form->max_x;
		++i;
	}
}

static void	ft_bruteforcerestart(t_fillit *fillit, int size)
{
	int	i;

	i = 0;
	fillit->totalprinted = 0;
	fillit->bruteforce_hit = 0;
	while (i < fillit->totaltype)
	{
		fillit->alltype[i]->printed = 0;
		fillit->alltype[i]->pos_x = -1;
		fillit->alltype[i]->pos_y = -1;
		++i;
	}
	ft_mapdel(&fillit->beta);
	if (!(fillit->beta = ft_mapinit(size)))
		ft_fillitdel(&fillit, 1);
	ft_bruteforcemaxsearch(fillit, size);
	ft_bruteforce(fillit);
}

static void	ft_bruteforcecalculmap(t_fillit *fillit)
{
	int	min_size;

	min_size = 0;
	while ((min_size * min_size) < (fillit->totaltype * 4))
		++min_size;
	min_size = (min_size < 4) ? 4 : min_size;
	if (!(fillit->beta = ft_mapinit(min_size)))
		ft_fillitdel(&fillit, 1);
	ft_bruteforcemaxsearch(fillit, min_size);
}

static void	ft_bruteforcesave(t_fillit *fillit)
{
	if (fillit->release)
		ft_mapdel(&fillit->release);
	if (!(fillit->release = ft_mapdup(fillit->beta)))
		ft_fillitdel(&fillit, 1);
}

void		ft_bruteforce(t_fillit *fillit)
{
	int	i;

	i = 0;
	if (!fillit->beta)
		ft_bruteforcecalculmap(fillit);
	while (i < fillit->totaltype && !ft_bruteforceelem(fillit, &i))
	{
		fillit->bruteforce_hit = 0;
		++i;
	}
	if (fillit->totalprinted == fillit->totaltype)
		ft_bruteforcesave(fillit);
	else
		ft_bruteforcerestart(fillit, fillit->beta->size + 1);
}
